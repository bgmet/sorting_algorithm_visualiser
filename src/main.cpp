#include <iostream>
#include <vector>

#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h>

#include "../lib/KnuthShuffle.hpp"

#include "../lib/BubbleSort.hpp"
#include "../lib/GnomeSort.hpp"
#include "../lib/InsertionSort.hpp"
#include "../lib/MergeSort.hpp"
#include "../lib/QuickSort.hpp"
#include "../lib/SelectionSort.hpp"
#include "../lib/Visualiser.hpp"

void thousand_quicksort();
void test();

int main()
{

    srand(time(0));

    thousand_quicksort();

    return 0;
}

void thousand_quicksort()
{
    KnuthShuffle knuth_shuffle(256);
    knuth_shuffle.init();
    knuth_shuffle.shuffle();

    std::vector<int> values = knuth_shuffle.get_values();

    QuickSort quick_sort(values);

    MergeSort merge_sort(values);

    Visualiser visualiser;

    visualiser.attach_sorter(&quick_sort);

    visualiser.run();
}

void test()
{
    std::vector<int> values = {83, 26, 47, 49, 58, 82, 65, 74, 17, 36, 56, 50, 33, 67, 99, 66, 78, 30, 89, 54, 22, 92, 62, 44, 1, 53, 38, 46, 79, 98, 21, 32, 5, 64, 3, 23, 29, 16, 69, 84, 11, 35, 42, 41, 85, 72, 96, 34, 61, 75, 48, 90, 15, 9, 8, 57, 93, 6, 77, 68, 94, 39, 81, 18, 87, 91, 73, 4, 28, 24, 45, 60, 43, 71, 63, 12, 7, 51, 59, 14, 37, 97, 55, 52, 70, 100, 88, 13, 40, 86, 20, 31, 80, 19, 2, 10, 27, 76, 95, 25};

    BubbleSort bubble_sort(values);

    InsertionSort insertion_sort(values);

    SelectionSort selection_sort(values);

    GnomeSort gnome_sort(values);

    Visualiser visualiser;

    visualiser.attach_sorter(&bubble_sort);

    visualiser.run();
}