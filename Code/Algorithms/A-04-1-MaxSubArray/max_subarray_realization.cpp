// Copyright [2017] <MaoMao>

#include "max_subarray_realization.h"


MaxSubArrayResult find_max_cross_subarray(int* array, int start, int middle, int end)
{
    int left_max = middle;
    int left_max_sum = array[middle];
    int right_max = middle+1;
    int right_max_sum = array[middle+1];

    // Check Left max
    int left_sum = 0;
    for (int i = middle; i >= start; i--)
    {
        left_sum += array[i];
        if (left_sum > left_max_sum)
        {
            left_max_sum = left_sum;
            left_max = i;
        }
    }

    // Check Right max
    int right_sum = 0;
    for (int i = middle+1; i <= end; i++)
    {
        right_sum += array[i];
        if (right_sum > right_max_sum)
        {
            right_max_sum = right_sum;
            right_max = i;
        }
    }

    MaxSubArrayResult result;
    result.start = left_max;
    result.end = right_max;
    result.sum = left_max_sum + right_max_sum;
    return result;
}

MaxSubArrayResult find_max_subarray(int* array, int start, int end)
{
    if (start == end)
    {
        MaxSubArrayResult result;
        result.start = start;
        result.end = end;
        result.sum = array[start];
        return result;
    }
    else
    {
        MaxSubArrayResult result_left;
        MaxSubArrayResult result_right;
        MaxSubArrayResult result_cross;
        int middle = (start + end) / 2;

        result_left = find_max_subarray(array, start, middle);
        result_right = find_max_subarray(array, middle+1, end);
        result_cross = find_max_cross_subarray(array, start, middle, end);

        if (result_left.sum > result_right.sum && result_left.sum > result_cross.sum)
            return result_left;
        else if (result_right.sum > result_left.sum && result_right.sum > result_cross.sum)
            return result_right;
        else
            return result_cross;
    }
}
