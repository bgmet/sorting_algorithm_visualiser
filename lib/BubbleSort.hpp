#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "SortingAlgorithm.hpp"

class BubbleSort : public SortingAlgorithm
{
private:
    std::vector<int> values;
    int i, j;
    bool done;
    int n_comparisons;

public:
    BubbleSort(const std::vector<int> &values_) : values(values_), i(0), j(0), done(false), n_comparisons(0) {}

    bool step() override;

    const std::vector<int> &get_values() const override;

    const void get_colors(int *a, int *b) const override;

    const int get_magnitude() const override;

    const int get_n_comparisons() const override;
};

#endif