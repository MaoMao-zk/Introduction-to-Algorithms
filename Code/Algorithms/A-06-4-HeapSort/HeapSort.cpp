#include "HeapSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

void MaxHeapify(int* array, int size, int i)
{
    while(i<size)
    {
        int left = i*2 + 1;
        int right = left + 1;
        int largest;
        
        if(left < size && array[left]>=array[i])
            largest = left;
        else
            largest = i;
        
        if(right < size && array[right]>=array[largest])
            largest = right;
        
        if(largest != i)
        {
            //exchange largest and head
            int tmp = array[i];
            array[i] = array[largest];
            array[largest] = tmp;

            i = largest;
        }
        else
            break;
    }
}

HeapSort::HeapSort()
{
    m_info.id = "A-6-4";
    m_info.name = "HeapSort";

    m_size = 0;
    m_array = NULL;
}

HeapSort::~HeapSort()
{
    if(m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void HeapSort::m_BuildInput()
{
    printf("Please input array size:\n");
    
    std::cin >> m_size;
    assert(m_size>0);

    m_array = new int[m_size];

    srand(time(NULL));
    for(int i=0;i<m_size;i++)
    {
        m_array[i] = rand()%(m_size*10);
        //printf("%d ", m_array[i]);
    }
    //std::cout<<endl;
}

void HeapSort::m_Execute()
{
    //1. Build max heap
    for(int i=m_size/2-1;i>=0;i--)
    {
        MaxHeapify(m_array, m_size, i);
    }

    //2. Find the max-value -> min-value one by one
    for(int size=m_size;size>=2;)
    {
        //2.1 exchange max value to end
        int tmp = m_array[0];
        m_array[0] = m_array[size-1];
        m_array[size-1] = tmp;

        //2.2 max heapity again
        size--;
        MaxHeapify(m_array, size, 0);
    }
}

bool HeapSort::m_CheckOutput()
{
    return Utils::CheckArraySort(m_array, m_size);
}