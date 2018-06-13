// Copyright [2017] <MaoMao>

int Parent(int i)
{
    if (i <= 0)
        return -1;
    else
        return (i - 1) / 2;
}

int Left(int i)
{
    return i * 2 + 1;
}

int Right(int i)
{
    return i * 2 + 2;
}

void MaxHeapify(int* array, int& length, int i)
{
    int large = i;
    int left = Left(i);
    int right = Right(i);
    if (right < length && array[right] > array[large])
        large = right;
    if (left < length && array[left] > array[large])
        large = left;

    if (large != i)
    {
        int tmp = array[i];
        array[i] = array[large];
        array[large] = tmp;
        MaxHeapify(array, length, large);
    }
}

int Maximum(int* array, int& length)
{
    return array[0];
}

int ExtractMax(int* array, int& length)
{
    if (length <= 0)
        return -1;

    int max = array[0];

    array[0] = array[length - 1];

    length--;

    MaxHeapify(array, length, 0);

    return max;
}

void IncreaseKey(int* array, int& length, int i, int key)
{
    array[i] = key;
    while (Parent(i) != -1)
    {
        int p = Parent(i);
        if (array[i] > array[p])
        {
            int tmp = array[i];
            array[i] = array[p];
            array[p] = tmp;
        }
        i = p;
    }
}

void Insert(int* array, int& length, int x)
{
    array[length] = x;
    length++;
    IncreaseKey(array, length, length - 1, x);
}
