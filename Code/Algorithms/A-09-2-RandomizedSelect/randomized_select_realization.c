// Copyright [2017] <MaoMao>

#include "Utils.h"
#include <stdlib.h>
#include <time.h>

extern int randomized_partition(int* array, int start, int end);

int randomized_select(int* array, int start, int end, int select)
{
    if (start == end)
        return array[start];

    int middle = randomized_partition(array, start, end);

    if (middle == select)
        return array[middle];
    else if (middle > select)
        return randomized_select(array, start, middle-1, select);
    else
        return randomized_select(array, middle+1, end, select);
}
