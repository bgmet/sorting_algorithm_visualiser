#include "../lib/KnuthShuffle.hpp"

const std::vector<int> &KnuthShuffle::get_values() const
{
    return values;
}

void KnuthShuffle::shuffle()
{
    if (values.size() <= 0)
    {
        std::cout << "The vector is empty" << std::endl;
        return;
    }

    for (int i = values.size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        std::swap(values[i], values[j]);
    }
}

void KnuthShuffle::init()
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = i;
    }
}