#ifndef SORTINGALGORITHM_HPP
#define SORTINGALGORITHM_HPP

// The functions step will do one sorting operation when called. Useful for the graphics handler;

#include <vector>

class SortingAlgorithm
{
public:
    virtual bool step() = 0;

    virtual const std::vector<int> &get_values() const = 0;

    virtual const void get_colors(int *a, int *b) const = 0;

    virtual const int get_magnitude() const = 0;

    virtual const int get_n_comparisons() const = 0;

    virtual ~SortingAlgorithm() = default;
};

#endif