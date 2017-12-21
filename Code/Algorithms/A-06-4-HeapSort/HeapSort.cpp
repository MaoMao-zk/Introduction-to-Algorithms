// Copyright [2017] <MaoMao>

#include "HeapSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern void heap_sort(int* array, int size);

HeapSort::HeapSort()
{
    m_info.id = "A-6-4";
    m_info.name = "HeapSort";

    m_size = 0;
    m_array = NULL;
}

HeapSort::~HeapSort()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void HeapSort::m_BuildInput()
{
    printf("Please input array size:\n");

    std::cin >> m_size;
    assert(m_size > 0);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = rand()%(m_size*10);
        // printf("%d ", m_array[i]);
    }
    // std::cout<<endl;
}

void HeapSort::m_Execute()
{
    heap_sort(m_array, m_size);
}

bool HeapSort::m_CheckOutput()
{
    return Utils::CheckArraySort(m_array, m_size);
}
