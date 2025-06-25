#ifndef GNOMESORT_HPP
#define GNOMESORT_HPP

#include "SortingAlgorithm.hpp"

class GnomeSort : public SortingAlgorithm
{
private:
    std::vector<int> values;
    int i;
    bool go_left;
    bool done;
    int n_comparisons;

public:
    // initially goes rightward
    GnomeSort(std::vector<int> &values_) : values(values_), i(0), go_left(false), done(false) {}

    bool step() override;

    const std::vector<int> &get_values() const override;

    const void get_colors(int *a, int *b) const override;

    const int get_magnitude() const override;

    const int get_n_comparisons() const override;
};

#endif