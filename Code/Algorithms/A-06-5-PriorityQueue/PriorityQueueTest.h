// Copyright [2017] <MaoMao>

#ifndef _PRIORITY_QUEUEU_TEST_H_
#define _PRIORITY_QUEUEU_TEST_H_

#include "Algorithms.h"

class PriorityQueueTest : public Algorithms
{
 public:
    PriorityQueueTest();
    virtual ~PriorityQueueTest();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    void Print(int* array, int& length);
    bool CheckHeap(int* array, int& length);
 private:
    int m_size;
    int m_length;
    int* m_array;
};

#endif
