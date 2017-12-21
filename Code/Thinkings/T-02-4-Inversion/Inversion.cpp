// Copyright [2017] <MaoMao>

#include "Inversion.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

extern long long inversion_count(int* array, int start, int end);

Inversion::Inversion()
{
    m_info.id = "T-2-4";
    m_info.name = "Inversion";

    m_size = 0;
    m_array = NULL;
    m_count = 0;
}

Inversion::~Inversion()
{
    if (m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void Inversion::m_BuildInput()
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


void Inversion::m_Execute()
{
    m_count = inversion_count(m_array, 0, m_size-1);
}

bool Inversion::m_CheckOutput()
{
    /*
    for(int i=0;i<m_size;i++)
    {
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;*/
    cout << "Inversion count is " << m_count << endl;
    return true;
}

