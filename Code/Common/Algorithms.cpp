// Copyright [2017] <MaoMao>

#include "Algorithms.h"
#include <assert.h>
#include <sys/time.h>
#include <stdint.h>

AlgorithmsInfo& Algorithms::GetInfo()
{
    assert(m_info.id != "");
    return m_info;
}
void Algorithms::Run()
{
    m_BuildInput();

    timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    m_Execute();

    gettimeofday(&tv2, NULL);
    int64_t used_time = (tv2.tv_sec*1000*1000 + tv2.tv_usec) - (tv1.tv_sec*1000*1000 + tv1.tv_usec);
    int64_t seconds = used_time / (1000*1000);
    used_time = used_time % (1000*1000);
    double mile_seconds = used_time / 1000.0;
    printf("Time used %lds %.3lfms\n", seconds, mile_seconds);

    bool result = m_CheckOutput();
    if (result)
        printf("Confratulations! PASS!\n");
    else
        printf("Sorry! FAIL!\n");
}
