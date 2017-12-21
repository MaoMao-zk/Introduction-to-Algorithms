// Copyright [2017] <MaoMao>

#include "MergeSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern void merge_sort(int* array, int start, int end);

MergeSort::MergeSort()
{
    m_info.id = "A-2-3";
    m_info.name = "MergeSort";

    m_size = 0;
    m_array = NULL;
}

MergeSort::~MergeSort()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void MergeSort::m_BuildInput()
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

void MergeSort::m_Execute()
{
    merge_sort(m_array, 0, m_size-1);
}

bool MergeSort::m_CheckOutput()
{
    return Utils::CheckArraySort(m_array, m_size);
}
