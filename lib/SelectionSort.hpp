#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "SortingAlgorithm.hpp"

class SelectionSort : public SortingAlgorithm
{
private:
    std::vector<int> values;
    int i, j;
    int mini;
    bool searching;
    bool done;
    int n_comparisons;

public:
    SelectionSort(std::vector<int> &values_) : values(values_), i(0), j(1), done(false), searching(true), mini(0) {}

    bool step() override;

    const std::vector<int> &get_values() const override;

    const void get_colors(int *a, int *b) const override;

    const int get_magnitude() const override;

    const int get_n_comparisons() const override;
};

#endif