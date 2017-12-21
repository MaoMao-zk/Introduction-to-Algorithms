// Copyright [2017] <MaoMao>

void max_heapify(int* array, int size, int i)
{
    while (i < size)
    {
        int left = i*2 + 1;
        int right = left + 1;
        int largest;

        if (left < size && array[left] >= array[i])
            largest = left;
        else
            largest = i;

        if (right < size && array[right] >= array[largest])
            largest = right;

        if (largest != i)
        {
            // exchange largest and head
            int tmp = array[i];
            array[i] = array[largest];
            array[largest] = tmp;

            i = largest;
        }
        else
            break;
    }
}

void heap_sort(int* array, int size)
{
    // 1. Build max heap
    for (int i = size/2-1; i >= 0; i--)
    {
        max_heapify(array, size, i);
    }

    // 2. Find the max-value -> min-value one by one
    for (; size >= 2; )
    {
        // 2.1 exchange max value to end
        int tmp = array[0];
        array[0] = array[size-1];
        array[size-1] = tmp;

        // 2.2 max heapity again
        size--;
        max_heapify(array, size, 0);
    }
}
