#ifndef KNUTHSHUFFLE_HPP
#define KNUTHSHUFFLE_HPP

#include <iostream>
#include <vector>

class KnuthShuffle
{
private:
    std::vector<int> values;

public:
    KnuthShuffle() : values() {}
    KnuthShuffle(int n) : values(std::vector<int>(n)) {}

    const std::vector<int> &get_values() const;
    void init();
    void shuffle();
};

#endif