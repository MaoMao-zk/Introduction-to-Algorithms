// Copyright [2017] <MaoMao>

#include "QuickSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern void quick_sort(int* array, int start, int end);
extern void randomized_quick_sort(int* array, int start, int end);

QuickSort::QuickSort()
{
    m_info.id = "A-7-1";
    m_info.name = "QuickSort";

    m_size = 0;
    m_array = NULL;
    m_use_randomized_quick_sort = 0;
}

QuickSort::~QuickSort()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void QuickSort::m_BuildInput()
{
    printf("Please input array size:\n");
    std::cin >> m_size;
    assert(m_size > 0);

    printf("Use randomized_quick_sort(1) or quick_sort(0)\n");
    std::cin >> m_use_randomized_quick_sort;
    assert(m_use_randomized_quick_sort == 0 || m_use_randomized_quick_sort == 1);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = rand()%(m_size*10);
    }

    // Utils::PrintArray(m_array, m_size);
    // m_Execute();
}

void QuickSort::m_Execute()
{
    if(m_use_randomized_quick_sort == 1)
        randomized_quick_sort(m_array, 0, m_size-1);
    else
        quick_sort(m_array, 0, m_size-1);
}

bool QuickSort::m_CheckOutput()
{
    // Utils::PrintArray(m_array, m_size);
    return Utils::CheckArraySort(m_array, m_size);
}
