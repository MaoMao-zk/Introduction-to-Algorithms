#include "CountingSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

void counting_sort(int* array, int size, int max_value)
{
    int* counting_array = new int[max_value];

    //initial
    for(int i=0;i<max_value;i++)
        counting_array[i] = 0;
    
    //counting
    for(int i=0;i<size;i++)
        counting_array[array[i]]++;

//Simple sorting
#if 1
    //sorting
    int i=0;
    for(int j=0;j<max_value;j++)
    {
        if(counting_array[j] != 0)
        {
            for(int k=0;k<counting_array[j];k++)
            {
                array[i] = j;
                i++;
            }
        }
    }
//Sorting in book
#else
    //counting_array[i] will be the right position of i
    for(int i=1;i<max_value;i++)
        counting_array[i] += counting_array[i-1];
    
    //sorting
    int* tmp_array = new int[size];
    for(int i=size-1;i>=0;i--)
    {
        tmp_array[counting_array[array[i]]-1] = array[i];
        counting_array[array[i]]--;
    }
    
    //copy to array
    for(int i=0;i<size;i++)
        array[i] = tmp_array[i];
#endif
}

CountingSort::CountingSort()
{
    m_info.id = "A-8-2";
    m_info.name = "CountingSort";

    m_size = 0;
    m_max_value = 0;
    m_array = NULL;
}

CountingSort::~CountingSort()
{
    if(m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void CountingSort::m_BuildInput()
{
    printf("Please input array size and max data value:\n");
    std::cin >> m_size >> m_max_value;
    assert(m_size>0);
    assert(m_max_value>0);

    m_array = new int[m_size];

    srand(time(NULL));
    for(int i=0;i<m_size;i++)
    {
        m_array[i] = rand()%(m_max_value);
    }
    //Utils::PrintArray(m_array, m_size);
}

void CountingSort::m_Execute()
{
    counting_sort(m_array, m_size, m_max_value);
}

bool CountingSort::m_CheckOutput()
{
    //Utils::PrintArray(m_array, m_size);
    return Utils::CheckArraySort(m_array, m_size);
}