#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <stack>

#include "SortingAlgorithm.hpp"

class QuickSort : public SortingAlgorithm
{
private:
    typedef struct Frame_s
    {
        int a, b; // index for the leftmost and rightmost values of current the subarray
        int i, j;
        enum
        {
            CALL,
            PARTITION
        } state;
    } Frame;
    // make use of a stack just like merge sort
    std::vector<int> values;
    std::stack<Frame> calls;
    bool done;
    bool stack_empty_once;
    int n_comparisons;

public:
    QuickSort(std::vector<int> &values_) : values(values_), calls(), done(false), stack_empty_once(false), n_comparisons(0) {}

    bool step() override;

    const void get_colors(int *a, int *b) const override;

    const std::vector<int> &get_values() const override;

    const int get_magnitude() const override;

    const int get_n_comparisons() const override;
};

#endif