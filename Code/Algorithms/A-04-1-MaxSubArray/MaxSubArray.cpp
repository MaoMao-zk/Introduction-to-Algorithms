// Copyright [2017] <MaoMao>

#include "MaxSubArray.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

extern MaxSubArrayResult find_max_subarray(int* array, int start, int end);

MaxSubArray::MaxSubArray()
{
    m_info.id = "A-4-1";
    m_info.name = "MaxSubArray";

    m_size = 0;
    m_array = NULL;
}

MaxSubArray::~MaxSubArray()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void MaxSubArray::m_BuildInput()
{
    printf("Please input array size:\n");

    std::cin >> m_size;
    assert(m_size > 0);

    m_array = new int[m_size];

    srand(time(NULL));
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = rand()%(m_size*10) - m_size*5;
        printf("%d ", m_array[i]);
    }
    std::cout << endl;
    /*
    // Example in book
    static int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    m_size = 16;
    m_array = array;
    */
}

void MaxSubArray::m_Execute()
{
    m_result = find_max_subarray(m_array, 0, m_size-1);
}

bool MaxSubArray::m_CheckOutput()
{
    printf("max subarray is :\n");

    for (int i = m_result.start; i <= m_result.end; i++)
    {
        printf("%d ", m_array[i]);
    }
    printf("\nsum is %d\n", m_result.sum);

    return true;
}
