#ifndef _INVERSION_H_
#define _INVERSION_H_

#include "Algorithms.h"

class Inversion : public Algorithms
{
public:
    Inversion();
    virtual ~Inversion();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual void m_CheckOutput();
private:
    static long long merge_sort(int* array, int start, int end);
    static long long merge(int* array, int start, int middle, int end);
private:
    int m_size;
    int* m_array;
    long long m_count;
};

#endif
