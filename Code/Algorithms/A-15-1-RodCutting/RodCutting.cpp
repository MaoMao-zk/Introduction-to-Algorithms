// Copyright [2017] <MaoMao>

#include "RodCutting.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern void rod_cutting(int* p, int n, int* r, int* s);

RodCutting::RodCutting()
{
    m_info.id = "A-15-1";
    m_info.name = "RodCutting";

    m_size = 0;
    m_price = NULL;
    m_resultPrice = NULL;
    m_resultCutting = NULL;
}

RodCutting::~RodCutting()
{
    if (m_price != NULL)
    {
        // delete []m_price;
        m_price = NULL;
    }
}

void RodCutting::m_BuildInput()
{
    m_size = 10;
    static int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    m_price = p;

    m_resultPrice = new int[10];
    m_resultCutting = new int[10];

    printf("Input: \n");
    for (int i = 0; i < 10; i++)
        printf("%-4d", i+1);
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("%-4d", p[i]);
    printf("\n");
}

void RodCutting::m_Execute()
{
    rod_cutting(m_price, m_size, m_resultPrice, m_resultCutting);
}

bool RodCutting::m_CheckOutput()
{
    printf("Result: \n");
    for (int i = 0; i < 10; i++)
        printf("%-4d", i+1);
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("%-4d", m_resultPrice[i]);
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("%-4d", m_resultCutting[i]);
    printf("\n");
    return true;
}
