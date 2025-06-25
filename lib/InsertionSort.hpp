#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "SortingAlgorithm.hpp"

class InsertionSort : public SortingAlgorithm
{
private:
    std::vector<int> values;
    int i, j;
    bool inserting;
    bool done;
    int n_comparisons;

public:
    InsertionSort(std::vector<int> &values_) : values(values_), i(0), j(0), inserting(false), done(false) {}

    bool step() override;

    const std::vector<int> &get_values() const override;

    const void get_colors(int *a, int *b) const override;

    const int get_magnitude() const override;

    const int get_n_comparisons() const override;
};

#endif