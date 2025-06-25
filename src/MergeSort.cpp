#include "../lib/MergeSort.hpp"

void merge(std::vector<int> &A, int a, int b, int c)
{
    int length_left = b - a + 1;
    int length_right = c - b;

    // Create subarrays
    std::vector<int> left(length_left);
    std::vector<int> right(length_right);

    // Copy values in the new subarray
    for (int i = 0; i < length_left; i++)
    {
        left[i] = A[a + i];
    }

    for (int i = 0; i < length_right; i++)
    {
        right[i] = A[b + i + 1];
    }

    // Both are sorted, change the value of A one by one
    int i = 0, j = 0, k = 0;
    while (i < length_left && j < length_right)
    {
        if (left[i] < right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    // Done when emptied a subarray
    while (i < length_left)
    {
        A[k] = left[i];
        i++;
        k++;
    }
    while (j < length_right)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> &A, int a, int c)
{
    if (A.size() == 1)
    {
        return;
    }

    int b = (a + c) / 2;
    merge_sort(A, a, b);
    merge_sort(A, b + 1, c);

    merge(A, a, b, c);
}

// Pop the top of a stack<frame>
// If CALL, find the middle of the interval (previous b)
// Stack 2 more frames
// If MERGE
// Decide on wether we want to do the full merge or just one by one

bool MergeSort::step()
{
    if (done)
    {
        return false;
    }

    if (calls.empty())
    {
        std::cout << "The stack is empty" << std::endl;
        if (stack_empty_once)
        {
            std::cout << "End of the program" << std::endl;
            done = true;
            return false;
        }
        std::cout << "This is just the beginning" << std::endl;

        stack_empty_once = true;

        Frame frame = {.a = 0, .c = static_cast<int>(values.size()), .state = Frame::CALL};
        calls.push(frame);
        return true;
    }

    Frame &e = calls.top();

    if (e.state == Frame::CALL)
    {
        if (e.a == e.c)
        {
            // The subarray is of length 1
            // We are done
            calls.pop();
            return true;
        }
        // We need to split the subarray in 2

        int b = (e.a + e.c) / 2;

        Frame m_sort_left = {.a = e.a, .c = b, .state = Frame::CALL};
        Frame m_sort_right = {.a = b + 1, .c = e.c, .state = Frame::CALL};
        Frame merge_both = {.a = e.a, .b = b, .c = e.c, .i = 0, .j = 0, .k = 0, .state = Frame::MERGE};

        calls.pop();
        // First do left then right then merge
        calls.push(merge_both);
        calls.push(m_sort_right);
        calls.push(m_sort_left);

        return true;
    }
    else
    {
        if (e.k == 0)
        {
            // First iteration: do copies
            e.left.resize(e.b + 1 - e.a);
            e.right.resize(e.c - e.b);

            for (int i = 0; i < e.left.size(); i++)
            {
                e.left[i] = values[e.a + i];
            }

            for (int i = 0; i < e.right.size(); i++)
            {
                e.right[i] = values[e.b + 1 + i];
            }
        }

        // Check bounds and merge one value
        if (e.i < e.left.size() && e.j < e.right.size())
        {
            // This is the while loop
            int value_left = e.left[e.i];
            int value_right = e.right[e.j];

            if (value_left < value_right)
            {
                n_comparisons++;
                values[e.a + e.k] = value_left;
                e.i++;
            }
            else
            {
                n_comparisons++;

                values[e.a + e.k] = value_right;
                e.j++;
            }
            e.k++;
        }
        else if (e.i < e.left.size())
        {
            values[e.a + e.k] = e.left[e.i];
            e.i++;
            e.k++;
        }
        else if (e.j < e.right.size())
        {
            values[e.a + e.k] = e.right[e.j];
            e.j++;
            e.k++;
        }
        else
        {
            calls.pop();
        }
        return true;
    }
    return false;
}

const std::vector<int> &MergeSort::get_values() const
{
    return values;
}

const void MergeSort::get_colors(int *a, int *b) const
{
    *a = 1;
    *b = 1;
}

const int MergeSort::get_magnitude() const
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

const int MergeSort::get_n_comparisons() const
{
    return n_comparisons;
}