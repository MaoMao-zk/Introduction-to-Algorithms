// Copyright [2017] <MaoMao>

#include "CountingSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

extern void counting_sort(int* array, int size, int max_value);

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
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void CountingSort::m_BuildInput()
{
    printf("Please input array size and max data value:\n");
    std::cin >> m_size >> m_max_value;
    assert(m_size > 0);
    assert(m_max_value > 0);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i  =0; i < m_size; i++)
    {
        m_array[i] = rand()%(m_max_value);
    }
    // Utils::PrintArray(m_array, m_size);
}

void CountingSort::m_Execute()
{
    counting_sort(m_array, m_size, m_max_value);
}

bool CountingSort::m_CheckOutput()
{
    // Utils::PrintArray(m_array, m_size);
    return Utils::CheckArraySort(m_array, m_size);
}
