// Copyright [2017] <MaoMao>

#include "Algorithms.h"
#include <assert.h>
#include <time.h>
#include <stdint.h>

AlgorithmsInfo& Algorithms::GetInfo()
{
    assert(m_info.id != "");
    return m_info;
}
void Algorithms::Run()
{
    m_BuildInput();

    clock_t c1, c2;
    c1 = clock();

    m_Execute();

    c2 = clock();
    printf("Time used %lds %ldms\n", (c2 - c1) / CLOCKS_PER_SEC, (c2 - c1) % CLOCKS_PER_SEC);

    bool result = m_CheckOutput();
    if (result)
        printf("Confratulations! PASS!\n");
    else
        printf("Sorry! FAIL!\n");
}
