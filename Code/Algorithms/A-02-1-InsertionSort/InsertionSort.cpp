// Copyright [2017] <MaoMao>

#include "InsertionSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern void insertion_sort(int* array, int size);

InsertionSort::InsertionSort()
{
    m_info.id = "A-2-1";
    m_info.name = "InsertionSort";

    m_size = 0;
    m_array = NULL;
}

InsertionSort::~InsertionSort()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void InsertionSort::m_BuildInput()
{
    printf("Please input array size:\n");
    std::cin >> m_size;
    assert(m_size > 0);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = rand()%(m_size*10);
        printf("%d ", m_array[i]);
    }
    std::cout << endl;
}

void InsertionSort::m_Execute()
{
    insertion_sort(m_array, m_size);
}

bool InsertionSort::m_CheckOutput()
{
    return Utils::CheckArraySort(m_array, m_size);
}
