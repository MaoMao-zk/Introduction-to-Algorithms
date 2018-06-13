// Copyright [2017] <MaoMao>

#include <string.h>
#include <stdio.h>

int activity_choice(int(*activity)[2], int num_sum, int*& result)
{
    int num = 0;
    int current_end = 0;

    result = new int[num_sum];

    for(int i = 0; i < num_sum; i++)
    {
        if (activity[i][0] >= current_end)
        {
            result[num] = i;
            num++;
            current_end = activity[i][1];
        }
    }
    return num;
}
