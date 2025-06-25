#include "../lib/Visualiser.hpp"

void Visualiser::attach_sorter(SortingAlgorithm *sorter)
{
    if (sorter == nullptr)
    {
        std::cout << "The sorter you passed is null" << std::endl;
        exit(1);
    }

    sorting_algorithm = sorter;
    std::cout << "The sorter you passed has been successfully attached to the visualiser" << std::endl;
}

void Visualiser::set_label(std::string label_)
{
    label = label_;
}

void Visualiser::write_banner(SDL_Renderer *renderer, std::string text)
{
    TTF_Init();
    std::cout << "Init happened" << std::endl;

    TTF_Font *font = TTF_OpenFont("/Library/Fonts/Arial.ttf", banner_height);
    std::cout << "open font happened" << std::endl;

    SDL_Color color = {255, 255, 255}; // White text

    std::string texte = std::to_string(sorting_algorithm->get_n_comparisons());

    const char *c_texte = texte.c_str();

    SDL_Surface *surface = TTF_RenderText_Blended(font, c_texte, texte.length(), color);
    std::cout << "render text blended happened" << std::endl;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    std::cout << "create texture from surface happened" << std::endl;

    SDL_FRect dst = {50, 50, (float)surface->w, (float)surface->h};

    SDL_RenderTexture(renderer, texture, NULL, &dst);
    std::cout << "render texture happened" << std::endl;

    // see about that later
    // SDL_RenderPresent(renderer);
    // SDL_DestroyTexture(texture);
}

void Visualiser::run()
{
    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        exit(0);
    }

    SDL_Window *window = SDL_CreateWindow("Sorting Algorithm Visualiser", window_width, window_height, 0);
    if (!window)
    {
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        exit(0);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        exit(0);
    }

    // The window is initialised
    // Now we will start the simulation
    // While not done, keep going

    if (sorting_algorithm == nullptr)
    {
        std::cout << "No sorting algorithm has been given" << std::endl;
        exit(0);
    }

    int magnitude = sorting_algorithm->get_magnitude();
    Uint32 start_time = SDL_GetTicks();
    Uint32 diff;

    // Now we have a sorting algorithm and we want to visualise it
    bool is_sorted = false;
    bool quit = false;
    while (!quit)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
                quit = true;
        }

        if (!is_sorted)
        {

            // Clear the screen witht the color black
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            is_sorted = !(sorting_algorithm->step()); // FLAG THIS; CAUSES PLANT

            // Start of the rendering
            const std::vector<int> values = sorting_algorithm->get_values();
            // width of a number
            const int n = values.size();

            int num_width = (window_width - 2 * padding) / n;

            int offset_x = window_width - (n * num_width);
            if (offset_x < 0)
            {
                std::cout << "Overflowing" << std::endl;
            }
            offset_x = offset_x / 2;

            int relative_height = window_height - 2 * padding - banner_height;

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // set the drawing color to white
            int current, comparison;
            sorting_algorithm->get_colors(&current, &comparison);
            for (int k = 0; k < n; k++)
            {
                // Draw rectangles for each number in values
                // Let's assume the values are between 1 and 100
                int num_height = values[k] * relative_height / magnitude;
                SDL_FRect rectangle = {.x = (float)k * num_width + offset_x,
                                       .y = (float)window_height - padding - num_height,
                                       .w = (float)num_width,
                                       .h = (float)num_height};
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                if (k == current)
                {
                    // SDL_SetRenderDrawColor(renderer, 102, 255, 102, 255);
                }
                else if (k == comparison)
                {

                    // SDL_SetRenderDrawColor(renderer, 255, 51, 0, 255);
                }

                SDL_RenderFillRect(renderer, &rectangle);
                // SDL_RenderDrawRect(renderer, &rectangle);
            }

            TTF_Init();

            TTF_Font *font = TTF_OpenFont("/Library/Fonts/Arial Unicode.ttf", banner_height);
            if (!font)
                std::cout << "Couldnt load font: " << SDL_GetError() << std::endl;

            SDL_Color color = {255, 255, 255}; // White text

            diff = SDL_GetTicks() - start_time;

            std::string texte = "number of comparisons:" + std::to_string(sorting_algorithm->get_n_comparisons()) + ", running time:" + std::to_string(diff) + "ms";

            const char *c_texte = texte.c_str();

            SDL_Surface *surface = TTF_RenderText_Blended(font, c_texte, texte.length(), color);
            if (!surface)
                std::cout << "Couldnt load surface: " << SDL_GetError() << std::endl;

            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

            SDL_FRect dst = {0, 0, (float)surface->w, (float)surface->h};

            SDL_RenderTexture(renderer, texture, NULL, &dst);

            // Draw the new array
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            SDL_RenderPresent(renderer);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

            SDL_DestroyTexture(texture);
            TTF_CloseFont(font);
            SDL_DestroySurface(surface);

            SDL_Delay(delay);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}