#include "YoungTableau.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

YoungTableau::YoungTableau()
{
    m_info.id = "T-6-3";
    m_info.name = "YoungTableau";
    
    m_tableau = NULL;
}

YoungTableau::~YoungTableau()
{
    if(m_tableau != NULL)
    {
        for(int i=0;i<m_size_m;i++)
        {
            delete [] m_tableau[i];
        }
        delete [] m_tableau;
    }
}

void YoungTableau::m_BuildInput()
{
    printf("Please input Tableau size(m * n) :\n");

    cin >> m_size_m >> m_size_n;
    assert(m_size_m>0);
    assert(m_size_n>0);

    m_tableau = new int*[m_size_m];
    for(int i=0;i<m_size_m;i++)
    {
        m_tableau[i] = new int[m_size_n];
    }
}

void YoungTableau::m_Execute()
{
    //printf("");
}

bool YoungTableau::m_CheckOutput()
{
    bool result = true;
    for(int i=0;i<m_size_m;i++)
    {
        for(int j=0;j<m_size_n;j++)
        {
            if(j<m_size_n-1 && m_tableau[i][j] > m_tableau[i][j+1])
            {
                result = false;
                break;
            }
            if(i<m_size_m-1 && m_tableau[i][j] > m_tableau[i+1][j])
            {
                result = false;
                break;
            }
        }
        if(!result)
            break;
    }
    return result;
}