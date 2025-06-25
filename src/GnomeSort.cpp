#include "../lib/GnomeSort.hpp"

bool GnomeSort::step()
{
    if (done)
    {
        return false;
    }

    if (i < values.size())
    {
        n_comparisons++;

        if (i == 0 || values[i - 1] <= values[i])
        {
            n_comparisons++;

            i = i + 1;
        }
        else
        {
            n_comparisons++;

            std::swap(values[i], values[i - 1]);
            i = i - 1;
        }
        return true;
    }
    else
    {
        n_comparisons++;

        done = true;
        return false;
    }
}

const std::vector<int> &GnomeSort::get_values() const
{
    return values;
}

void gnome_sort(std::vector<int> &A)
{
    int i = 0;
    while (i < A.size())
    {
        if (i == 0 || A[i - 1] <= A[i])
        {
            i = i + 1;
        }
        else
        {
            std::swap(A[i], A[i + 1]);
            i = i - 1;
        }
    }
}

const void GnomeSort::get_colors(int *a, int *b) const
{
    *a = i;
    *b = i;
}

const int GnomeSort::get_magnitude() const
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

const int GnomeSort::get_n_comparisons() const
{
    return n_comparisons;
}