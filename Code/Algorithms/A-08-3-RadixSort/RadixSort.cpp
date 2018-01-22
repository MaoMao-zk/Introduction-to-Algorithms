// Copyright [2017] <MaoMao>

#include "RadixSort.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

extern void radix_sort(int32_t* array, int size);

RadixSort::RadixSort()
{
    m_info.id = "A-8-3";
    m_info.name = "RadixSort";

    m_size = 0;
    m_array = NULL;
}

RadixSort::~RadixSort()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void RadixSort::m_BuildInput()
{
    printf("Please input array size:\n");
    std::cin >> m_size;
    assert(m_size > 0);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i  =0; i < m_size; i++)
    {
        m_array[i] = rand();
    }
    // Utils::PrintArray(m_array, m_size);
}

void RadixSort::m_Execute()
{
    radix_sort(m_array, m_size);
}

bool RadixSort::m_CheckOutput()
{
    // Utils::PrintArray(m_array, m_size);
    return Utils::CheckArraySort(m_array, m_size);
}
