#include "../lib/QuickSort.hpp"

int partition(std::vector<int> &A, int a, int b)
{
    // Choose a pivot
    int pivot = A[b];

    // This will the position of the pivot at the end
    int i = a - 1;

    // Put all elements smaller than the pivot on the left
    // Do swaps when needed
    for (int j = a; j < b; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[b]);

    return i + 1;
}

void quick_sort(std::vector<int> &A, int a, int b)
{
    if (a < b)
    {
        int pivoted = partition(A, a, b);

        quick_sort(A, a, pivoted - 1);
        quick_sort(A, pivoted + 1, b);
    }
}

bool QuickSort::step()
{
    if (done)
    {
        return false;
    }

    if (calls.empty())
    {
        if (stack_empty_once)
        {
            done = false;
            return false;
        }

        stack_empty_once = true;

        // int size = dynamic_cast<QuickSort>(values)

        Frame frame = {.a = 0, .b = static_cast<int>(values.size()) - 1, .state = Frame::CALL};
        calls.push(frame);
    }

    Frame e = calls.top();
    calls.pop();
    // Do not forget to pop

    if (e.state == Frame::CALL)
    {
        if (e.a < e.b)
        {
            Frame frame = {.a = e.a, .b = e.b, .i = e.a - 1, .j = e.a, .state = Frame::PARTITION};
            calls.push(frame);
        }
        return true;
    }

    else /* if (e.state == Frame::PARTITION)*/
    {
        // Frame::PARTITION
        int pivot = values[e.b];
        if (e.j < e.b)
        {
            // still in the for loop
            n_comparisons++;
            if (values[e.j] < pivot)
            {
                e.i++;
                std::swap(values[e.i], values[e.j]);
            }
            e.j++;
            Frame frame = {.a = e.a, .b = e.b, .i = e.i, .j = e.j, .state = Frame::PARTITION};
            calls.push(frame);
        }
        else
        {
            // outside of the imaginary for loop
            std::swap(values[e.i + 1], values[e.b]);

            // return i + 1 // pretty much means stack up a FRAME::FINAL_PARTITION
            int pi = e.i + 1;
            Frame qs_left = {.a = e.a, .b = pi - 1, .state = Frame::CALL};
            Frame qs_right = {.a = pi + 1, .b = e.b, .state = Frame::CALL};
            calls.push(qs_right);
            calls.push(qs_left);
        }
        return true;
    }
}

const std::vector<int> &QuickSort::get_values() const
{
    return values;
}

const void QuickSort::get_colors(int *a, int *b) const
{
    // Do later, not interesting yet
    *a = 1;
    *b = 1;
}

const int QuickSort::get_magnitude() const
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

const int QuickSort::get_n_comparisons() const
{
    return n_comparisons;
}