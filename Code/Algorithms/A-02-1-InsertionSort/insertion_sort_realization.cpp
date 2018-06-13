// Copyright [2017] <MaoMao>

void insertion_sort(int* array, int size)
{
    // When i is x, means the 0~x-1 of array is sorted.
    for (int i = 1; i < size; i++)
    {
        int current = array[i];
        int j = i-1;
        // Copy array[j] -> array[j+1], until find the place to insert array[i]
        for (; j >= 0 && array[j] > current; j--)
        {
            array[j+1] = array[j];
        }
        array[j+1] = current;
    }
}
