#ifndef _MAX_SUB_ARRAY_H_
#define _MAX_SUB_ARRAY_H_

#include "Algorithms.h"

struct MaxSubArrayResult
{
    int start;
    int end;
    int sum;
};

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
    static MaxSubArrayResult find_max_subarray(int* array, int start, int end);
    static MaxSubArrayResult find_max_cross_subarray(int* array, int start, int middle, int end);
private:
    int m_size;
    int* m_array;

    MaxSubArrayResult m_result;
};

#endif
