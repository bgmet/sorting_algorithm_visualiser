#ifndef VISUALISER_HPP
#define VISUALISER_HPP

#include <charconv>
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_time.h>
#include "SortingAlgorithm.hpp"

class Visualiser
{
private:
    SortingAlgorithm *sorting_algorithm;
    int window_width, window_height; // in pixels
    int delay;                       // in milliseconds
    int banner_height;               // pixels for the text, top of the window
    int padding;
    std::string label;

public:
    Visualiser() : sorting_algorithm(nullptr), window_width(1600), window_height(900), delay(0), banner_height(30), padding(6), label()
    {
    }

    void write_banner(SDL_Renderer *renderer, std::string text);
    void attach_sorter(SortingAlgorithm *sorter);
    void run();
    void set_label(std::string label_);
};

#endif