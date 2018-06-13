// Copyright [2017] <MaoMao>

void merge(int* array, int start, int middle, int end)
{
    // printf("merge %d to %d to %d\n", start, middle, end);
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
        }
    }
}

void merge_sort(int* array, int start, int end)
{
    // printf("merge_sort %d to %d\n", start, end);
    if (start < end)
    {
        int middle = start + ((end-start)/2);
        // Sort left-half array
        merge_sort(array, start, middle);
        // Sort right-half array
        merge_sort(array, middle+1, end);
        // Merge "left-half array" and "right-half array" to 1 sorted array
        merge(array, start, middle, end);
    }
}

