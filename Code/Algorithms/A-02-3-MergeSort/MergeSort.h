#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "Algorithms.h"

class MergeSort : public Algorithms
{
public:
    MergeSort();
    virtual ~MergeSort();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    static void merge_sort(int* array, int start, int end);
    static void merge(int* array, int start, int middle, int end);
private:
    int m_size;
    int* m_array;
};

#endif
