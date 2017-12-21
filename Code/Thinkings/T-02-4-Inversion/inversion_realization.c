// Copyright [2017] <MaoMao>

#include <stdint.h>

int64_t inversion_merge_count(int* array, int start, int middle, int end)
{
    int64_t count = 0;
    int ll = middle-start+2;
    int rl = end-middle+1;
    int* LA = new int[ll];
    int* RA = new int[rl];

    // Copy left-half and right-half to LA & RA
    for (int i = 0; i < ll-1; i++)
    {
        LA[i] = array[start + i];
    }
    LA[ll-1] = -1;
    for (int i = 0; i < rl-1; i++)
    {
        RA[i] = array[middle + 1 + i];
    }
    RA[rl-1] = -1;

    // copy data in LA & RA array to array as sorted
    int i = 0;
    int j = 0;
    for (int k = start; k <= end; k++)
    {
        if ((LA[i] <= RA[j] && LA[i] != -1) || RA[j] == -1)
        {
            array[k] = LA[i];
            i++;
        }
        else
        {
            array[k] = RA[j];
            j++;
            count += ll-1 - i;
        }
    }

    return count;
}

int64_t inversion_count(int* array, int start, int end)
{
    if (start < end)
    {
        int middle = start + ((end-start)/2);
        int64_t count = 0;
        // Count left-half array
        count += inversion_count(array, start, middle);
        // Count right-half array
        count += inversion_count(array, middle+1, end);
        // Merge "left-half array" and "right-half array" to 1 sorted array
        // Count inversion on both sides of middle
        count += inversion_merge_count(array, start, middle, end);
        return count;
    }
    else
        return 0;
}
