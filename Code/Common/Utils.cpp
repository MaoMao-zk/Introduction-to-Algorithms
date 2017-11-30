#include "Utils.h"


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