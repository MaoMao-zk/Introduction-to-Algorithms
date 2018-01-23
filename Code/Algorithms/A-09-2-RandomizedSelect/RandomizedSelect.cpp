// Copyright [2017] <MaoMao>

#include "RandomizedSelect.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern int  randomized_select(int* array, int start, int end, int select);

// For check output
extern void quick_sort(int* array, int start, int end);

RandomizedSelect::RandomizedSelect()
{
    m_info.id = "A-9-2";
    m_info.name = "RandomizedSelect";

    m_size = 0;
    m_array = NULL;
    m_select = -1;
}

RandomizedSelect::~RandomizedSelect()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void RandomizedSelect::m_BuildInput()
{
    printf("Please input array size:\n");
    std::cin >> m_size;
    assert(m_size > 0);

    printf("Input the i smallest element:(0~size-1)\n");
    std::cin >> m_select;
    assert(m_select >= 0 || m_select < m_size);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = rand()%(m_size*10);
    }

    // Utils::PrintArray(m_array, m_size);
    // m_Execute();
}

void RandomizedSelect::m_Execute()
{
    m_selected = randomized_select(m_array, 0, m_size-1, m_select);
}

bool RandomizedSelect::m_CheckOutput()
{
    int* array_copy = new int[m_size];

    for (int i = 0; i < m_size; i++)
    {
        array_copy[i] = m_array[i];
    }

    quick_sort(array_copy, 0, m_size-1);

    // Utils::PrintArray(m_array, m_size);
    return array_copy[m_select] == m_selected;
}
