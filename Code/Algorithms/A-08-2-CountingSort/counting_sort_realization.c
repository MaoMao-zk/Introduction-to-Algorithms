// Copyright [2017] <MaoMao>

void counting_sort(int* array, int size, int max_value)
{
    int* counting_array = new int[max_value];

    // initial
    for (int i = 0; i  <max_value; i++)
        counting_array[i] = 0;

    // counting
    for (int i = 0; i < size; i++)
        counting_array[array[i]]++;

// Simple sorting
#if 0
    // sorting
    int i = 0;
    for (int j = 0; j < max_value; j++)
    {
        if (counting_array[j] != 0)
        {
            for (int k = 0; k < counting_array[j]; k++)
            {
                array[i] = j;
                i++;
            }
        }
    }
// Sorting in book
#else
    // counting_array[i] will be the right position of i
    for (int i  = 1; i  < max_value; i++)
        counting_array[i] += counting_array[i-1];

    // sorting
    int* tmp_array = new int[size];
    for (int i  = size-1; i  >= 0; i--)
    {
        tmp_array[counting_array[array[i]]-1] = array[i];
        counting_array[array[i]]--;
    }

    // copy to array
    for (int i  = 0; i  < size; i++)
        array[i] = tmp_array[i];
#endif
}
