#include "../lib/InsertionSort.hpp"

bool InsertionSort::step()
{
    if (done)
        return false;

    if (!inserting)
    {
        // shifting elements
        if (j > 0 && values[j] <= values[j - 1])
        {
            n_comparisons++;

            std::swap(values[j - 1], values[j]);
            j = j - 1;
            return true;
        }
        else
        {
            if (j > 0)
            {
                n_comparisons++;
            }

            inserting = true;
            return true;
        }
    }

    else
    {

        // inserting elements
        i = i + 1;
        if (i >= values.size())
        {
            done = true;
            return false;
        }
        j = i;
        inserting = false;
        return true;
    }
}

const std::vector<int> &InsertionSort::get_values() const
{
    return values;
}

void insertion_sort(std::vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int j = i;
        while (j > 0 && A[j - 1] > A[j])
        {
            std::swap(A[j - 1], A[j]);
            j = j - 1;
        }
    }
}
const void InsertionSort::get_colors(int *a, int *b) const
{
    *a = i;
    *b = j;
}

const int InsertionSort::get_magnitude() const
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

const int InsertionSort::get_n_comparisons() const
{
    return n_comparisons;
}