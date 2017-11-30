#include "MaxSubArray.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

MaxSubArray::MaxSubArray()
{
    m_info.id = "A-4-1";
    m_info.name = "MaxSubArray";

    m_size = 0;
    m_array = NULL;
}

MaxSubArray::~MaxSubArray()
{
    if(m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void MaxSubArray::m_BuildInput()
{
    printf("Please input array size:\n");
    
    std::cin >> m_size;
    assert(m_size>0);

    m_array = new int[m_size];

    srand(time(NULL));
    for(int i=0;i<m_size;i++)
    {
        m_array[i] = rand()%(m_size*10) - m_size*5;
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;
    /*
    //Example in book
    static int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    m_size = 16;
    m_array = array;
    */
}

MaxSubArrayResult MaxSubArray::find_max_cross_subarray(int* array, int start, int middle, int end)
{
    int left_max = middle;
    int left_max_sum = array[middle];
    int right_max = middle+1;
    int right_max_sum = array[middle+1];

    //Check Left max
    int left_sum = 0;
    for(int i=middle;i>=start;i--)
    {
        left_sum += array[i];
        if(left_sum > left_max_sum)
        {
            left_max_sum = left_sum;
            left_max = i;
        }
    }

    //Check Right max
    int right_sum = 0;
    for(int i=middle+1;i<=end;i++)
    {
        right_sum += array[i];
        if(right_sum > right_max_sum)
        {
            right_max_sum = right_sum;
            right_max = i;
        }
    }

    //printf("find_max_cross_subarray(%d, %d, %d) -> [%d, %d, %d]\n", start, middle, end, left_max, right_max, left_max_sum + right_max_sum);
    MaxSubArrayResult result;
    result.start = left_max;
    result.end = right_max;
    result.sum = left_max_sum + right_max_sum;
    return result;
}

MaxSubArrayResult MaxSubArray::find_max_subarray(int* array, int start, int end)
{
    if(start == end)
    {
        MaxSubArrayResult result;
        result.start = start;
        result.end = end;
        result.sum = array[start];
        return result;
    }
    else
    {
        MaxSubArrayResult result_left;
        MaxSubArrayResult result_right;
        MaxSubArrayResult result_cross;
        int middle = (start + end) / 2;

        result_left = find_max_subarray(array, start, middle);
        result_right = find_max_subarray(array, middle+1, end);
        result_cross = find_max_cross_subarray(array, start, middle, end);

        if(result_left.sum > result_right.sum && result_left.sum > result_cross.sum)
            return result_left;
        else if(result_right.sum > result_left.sum && result_right.sum > result_cross.sum)
            return result_right;
        else
            return result_cross;
    }
}

void MaxSubArray::m_Execute()
{
    m_result = find_max_subarray(m_array, 0, m_size-1);
}

bool MaxSubArray::m_CheckOutput()
{
    printf("max subarray is :\n");

    for(int i=m_result.start;i<=m_result.end;i++)
    {
        printf("%d ", m_array[i]);
    }
    printf("\nsum is %d\n", m_result.sum);

    return true;
}