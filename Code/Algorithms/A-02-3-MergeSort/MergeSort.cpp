#include "MergeSort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

MergeSort::MergeSort()
{
    m_info.id = "A-2-3";
    m_info.name = "MergeSort";

    m_size = 0;
    m_array = NULL;
}

MergeSort::~MergeSort()
{
    if(m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void MergeSort::m_BuildInput()
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

void merge(int* array, int start, int middle, int end)
{
    //printf("merge %d to %d to %d\n", start, middle, end);
    int ll = middle-start+2;
    int rl = end-middle+1;
    int* LA = new int[ll];
    int* RA = new int[rl];

    //Copy left-half and right-half to LA & RA
    for(int i=0;i<ll-1;i++)
    {
        LA[i] = array[start + i];
    }
    LA[ll-1] = -1;
    for(int i=0;i<rl-1;i++)
    {
        RA[i] = array[middle + 1 + i];
    }
    RA[rl-1] = -1;

    //copy data in LA & RA array to array as sorted
    int i = 0;
    int j = 0;
    for(int k=start;k<=end;k++)
    {
        if((LA[i] <= RA[j] && LA[i] != -1) || RA[j] == -1)
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
    //printf("merge_sort %d to %d\n", start, end);
    if(start < end)
    {
        int middle = start + ((end-start)/2);
        //Sort left-half array
        merge_sort(array, start, middle);
        //Sort right-half array
        merge_sort(array, middle+1, end);
        //Merge "left-half array" and "right-half array" to 1 sorted array
        merge(array, start, middle, end);
    }
}

void MergeSort::m_Execute()
{
    merge_sort(m_array, 0, m_size-1);
}

void MergeSort::m_CheckOutput()
{
    /*
    for(int i=0;i<m_size;i++)
    {
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;*/
}