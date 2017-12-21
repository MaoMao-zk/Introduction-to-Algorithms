// Copyright [2017] <MaoMao>

#include "Utils.h"

int partition(int* array, int start, int end)
{
    int x = array[end];
    int i = start -1;
    int j = start;

    while (j < end)
    {
        if (array[j] <= x)
        {
            i++;
            // exchange min value to i-area
            Utils::Exchange(&array[i], &array[j]);
        }
        j++;
    }
    // exchange end value to right place
    Utils::Exchange(&array[i+1], &array[end]);
    return i+1;
}

void quick_sort(int* array, int start, int end)
{
    if (start < end)
    {
        int middle = partition(array, start, end);
        quick_sort(array, start, middle - 1);
        quick_sort(array, middle + 1, end);
    }
}
