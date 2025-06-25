#include "../lib/BubbleSort.hpp"

bool BubbleSort::step()
{
    if (done)
        return false;

    if (j > values.size() - 2 - i) // safer: j + 1 must be valid
    {
        n_comparisons++;

        j = 0;
        i += 1;
        if (i >= values.size() - 1)
        {
            n_comparisons++;

            done = true;
            return false;
        }
    }

    if (values[j] > values[j + 1])
    {
        n_comparisons++;

        std::swap(values[j], values[j + 1]);
    }

    j += 1;
    return true;
}

const std::vector<int> &BubbleSort::get_values() const
{
    return values;
}

const void BubbleSort::get_colors(int *a, int *b) const
{
    *a = i;
    *b = j;
}

const int BubbleSort::get_magnitude() const
{
    int mini = values[0];
    int maxi = values[0];
    for (int i = 0; i < values.size(); i++)
    {
        maxi = maxi > values[i] ? maxi : values[i];
        mini = mini > values[i] ? values[i] : mini;
    }
    return (maxi - mini);
}

const int BubbleSort::get_n_comparisons() const
{
    return n_comparisons;
}