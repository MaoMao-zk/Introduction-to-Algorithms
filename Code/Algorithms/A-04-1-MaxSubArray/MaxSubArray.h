#ifndef _MAX_SUB_ARRAY_H_
#define _MAX_SUB_ARRAY_H_

#include "Algorithms.h"
#include "max_subarray_realization.h"

class MaxSubArray : public Algorithms
{
public:
    MaxSubArray();
    virtual ~MaxSubArray();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    int m_size;
    int* m_array;

    MaxSubArrayResult m_result;
};

#endif
