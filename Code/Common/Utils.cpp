#include "Utils.h"
#include <stdio.h>

bool Utils::CheckArraySort(int* array, int size)
{
    bool result = true;

    for(int i=0;i<size-1;i++)
    {
        if(array[i+1] < array[i])
        {
            result = false;
            break;
        }
    }

    return result;
}

void Utils::PrintArray(int* array, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void Utils::Exchange(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}