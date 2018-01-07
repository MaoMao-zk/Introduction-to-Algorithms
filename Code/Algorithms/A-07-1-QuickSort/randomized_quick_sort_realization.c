// Copyright [2017] <MaoMao>

#include "Utils.h"
#include <stdlib.h>
#include <time.h>

int randomized_partition(int* array, int start, int end)
{
    // Chose a random data to end
    int pos = start + (rand() % (end - start));
    Utils::Exchange(&array[pos], &array[end]);

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

void randomized_quick_sort(int* array, int start, int end)
{
    if (start < end)
    {
        int middle = randomized_partition(array, start, end);
        randomized_quick_sort(array, start, middle - 1);
        randomized_quick_sort(array, middle + 1, end);
    }
}
