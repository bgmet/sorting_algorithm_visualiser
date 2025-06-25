#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <stack>
#include <vector>

#include "SortingAlgorithm.hpp"

// cf .cpp for more information on implementation

class MergeSort : public SortingAlgorithm
{
private:
    typedef struct Frame_s
    {
        int a, b, c; // index for the leftmost and rightmost values of current the subarray
        int i, j, k;
        enum
        {
            CALL,
            MERGE
        } state;
        std::vector<int> left, right;
    } Frame;
    std::vector<int> values;
    std::stack<Frame> calls;
    bool done;
    bool stack_empty_once; // to stop the sorting
    int n_comparisons;

public:
    MergeSort(std::vector<int> &values_) : values(values_), calls(), done(false), stack_empty_once(false) {}

    bool step() override;

    const void get_colors(int *a, int *b) const override;

    const std::vector<int> &get_values() const override;

    const int get_magnitude() const override;

    const int get_n_comparisons() const override;
};

#endif