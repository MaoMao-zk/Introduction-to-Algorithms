#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "Algorithms.h"

class QuickSort : public Algorithms
{
public:
    QuickSort();
    virtual ~QuickSort();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    static void quick_sort(int* array, int start, int end);
    static int partition(int* array, int start, int end);
private:
    int m_size;
    int* m_array;
};

#endif
