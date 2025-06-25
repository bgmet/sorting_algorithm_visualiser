#include "../lib/SelectionSort.hpp"

bool SelectionSort::step()
{
    if (done)
    {
        return false;
    }

    if (searching)
    {
        if (j < values.size())
        {
            n_comparisons++;
            if (values[j] < values[mini])
            {
                mini = j;
            }
            j = j + 1;
            return true;
        }
        else
        {
            searching = false;
            return true;
        }
    }
    else
    {
        std::swap(values[mini], values[i]);
        i = i + 1;
        if (i >= values.size())
        {
            done = true;
            return false;
        }
        j = i + 1;
        mini = i;
        searching = true;
        return true;
    }
}

const std::vector<int> &SelectionSort::get_values() const
{
    return values;
}

void selection_sort(std::vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int mini = i;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[mini] > A[j])
                mini = j;
        }
        std::swap(A[mini], A[i]);
    }
}

const void SelectionSort::get_colors(int *a, int *b) const
{
    *a = i;
    *b = j;
}

const int SelectionSort::get_magnitude() const
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

const int SelectionSort::get_n_comparisons() const
{
    return n_comparisons;
}