#include "InsertionSort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

InsertionSort::InsertionSort()
{
    m_info.id = "2-1";
    m_info.name = "InsertionSort";

    m_size = 0;
    m_array = NULL;
}

InsertionSort::~InsertionSort()
{
    if(m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void InsertionSort::m_BuildInput()
{
    printf("Please input array size:\n");
    std::cin >> m_size;
    assert(m_size>0);

    m_array = new int[m_size];

    srand(time(NULL));
    for(int i=0;i<m_size;i++)
    {
        m_array[i] = rand()%(m_size*10);
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;
}

void InsertionSort::m_Execute()
{
    //When i is x, means the 0~x-1 of array is sorted.
    for(int i=1;i<m_size;i++)
    {
        int current = m_array[i];
        int j=i-1;
        //Copy array[j] -> array[j+1], until find the place to insert array[i]
        for(;j>=0 && m_array[j]>current;j--)
        {
            m_array[j+1] = m_array[j];
        }
        m_array[j+1] = current;
    }
}

void InsertionSort::m_CheckOutput()
{
    for(int i=0;i<m_size;i++)
    {
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;
}