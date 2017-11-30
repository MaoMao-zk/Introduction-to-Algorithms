#include "Inversion.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Inversion::Inversion()
{
    m_info.id = "T-2-4";
    m_info.name = "Inversion";

    m_size = 0;
    m_array = NULL;
    m_count = 0;
}

Inversion::~Inversion()
{
    if(m_array != NULL)
    {
        delete []m_array;
        m_array = NULL;
    }
}

void Inversion::m_BuildInput()
{
    printf("Please input array size:\n");
    std::cin >> m_size;
    assert(m_size>0);

    m_array = new int[m_size];

    srand(time(NULL));
    for(int i=0;i<m_size;i++)
    {
        m_array[i] = rand()%(m_size*10);
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;
}

long long Inversion::merge(int* array, int start, int middle, int end)
{
    //printf("merge %d to %d to %d\n", start, middle, end);
    long long count = 0;
    int ll = middle-start+2;
    int rl = end-middle+1;
    int* LA = new int[ll];
    int* RA = new int[rl];

    //Copy left-half and right-half to LA & RA
    for(int i=0;i<ll-1;i++)
    {
        LA[i] = array[start + i];
    }
    LA[ll-1] = -1;
    for(int i=0;i<rl-1;i++)
    {
        RA[i] = array[middle + 1 + i];
    }
    RA[rl-1] = -1;

    //copy data in LA & RA array to array as sorted
    int i = 0;
    int j = 0;
    for(int k=start;k<=end;k++)
    {
        if((LA[i] <= RA[j] && LA[i] != -1) || RA[j] == -1)
        {
            array[k] = LA[i];
            i++;
        }
        else
        {
            array[k] = RA[j];
            j++;
            count += ll-1 - i;
        }
    }

    return count;
}

long long Inversion::merge_sort(int* array, int start, int end)
{
    //printf("merge_sort %d to %d\n", start, end);
    if(start < end)
    {
        int middle = start + ((end-start)/2);
        long long count = 0;
        //Sort left-half array
        count += merge_sort(array, start, middle);
        //Sort right-half array
        count += merge_sort(array, middle+1, end);
        //Merge "left-half array" and "right-half array" to 1 sorted array
        count += merge(array, start, middle, end);
        return count;
    }
    else
        return 0;
}

void Inversion::m_Execute()
{
    m_count = merge_sort(m_array, 0, m_size-1);
}

bool Inversion::m_CheckOutput()
{
    /*
    for(int i=0;i<m_size;i++)
    {
        printf("%d ", m_array[i]);
    }
    std::cout<<endl;*/
    cout << "Inversion count is " << m_count << endl;
    return true;
}