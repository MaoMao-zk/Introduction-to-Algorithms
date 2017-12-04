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
    m_size_m = 0;
    m_size_n = 0;
    m_current_size = 0;
    m_last[0] = -1;
    m_last[1] = -1;
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

int YoungTableau::m_ExtractMin(int** tableau, int m, int n, int& current_size)
{
    if(current_size<=0)
        return -1;
    
    int min = tableau[0][0];

    current_size--;

    //no data left
    if(current_size == 0)
    {
        tableau[0][0] = -1;
        return min;
    }

    //1. exchange last data to first position
    int last_r = current_size / n;
    int last_c = current_size % n;
    tableau[0][0] = tableau[last_r][last_c];
    tableau[last_r][last_c] = -1;

    //printf("m=%d, n=%d, current_size=%d, last_r=%d, last_c=%d \n", m, n, current_size, last_r, last_c);

    //m_Print();

    //2. move data in first postion to right positon
    int i=0;
    int j=0;
    do
    {
        //exchange current data with min data in right data and down data
        int exchange_r = i, exchange_c = j;
        //check right
        if(j+1<n && tableau[i][j+1] != -1 && tableau[i][j+1] < tableau[i][j])
        {
            exchange_r = i;
            exchange_c = j+1;
        }
        //chack down
        if(i+1<n && tableau[i+1][j] != -1 && tableau[i+1][j] < tableau[exchange_r][exchange_c])
        {
            exchange_r = i+1;
            exchange_c = j;
        }

        //have in right positon
        if(exchange_r == i && exchange_c == j)
            break;
        else
        {
            //exchange
            int tmp = tableau[i][j];
            tableau[i][j] = tableau[exchange_r][exchange_c];
            tableau[exchange_r][exchange_c] = tmp;
            i = exchange_r;
            j = exchange_c;
        }
    }while(1);

    return min;
}

bool YoungTableau::m_Insert(int** tableau, int m, int n, int& current_size, int a)
{
    //Fule
    if(current_size == m*n)
        return false;
    
    current_size++;

    if(current_size == 1)
    {
        tableau[0][0] = a;
        return true;
    }

    //1. set 'a' to last positon
    int last_r = (current_size-1) / n;
    int last_c = (current_size-1) % n;
    tableau[last_r][last_c] = a;

    //printf("m=%d, n=%d, current_size=%d, a=%d, last_r=%d, last_c=%d \n", m, n, current_size, a, last_r, last_c);

    //m_Print();

    //move 'a' n to right positon
    int i=last_r;
    int j=last_c;
    do
    {
        //exchange current data with max data in left data and up data
        int exchange_r = i, exchange_c = j;
        //check left
        if(j>0 && tableau[i][j-1] > tableau[i][j])
        {
            exchange_r = i;
            exchange_c = j-1;
        }
        //chack up
        if(i>0 && tableau[i-1][j] > tableau[exchange_r][exchange_c])
        {
            exchange_r = i-1;
            exchange_c = j;
        }

        //have in right positon
        if(exchange_r == i && exchange_c == j)
            break;
        else
        {
            //exchange
            int tmp = tableau[i][j];
            tableau[i][j] = tableau[exchange_r][exchange_c];
            tableau[exchange_r][exchange_c] = tmp;
            i = exchange_r;
            j = exchange_c;
        }
    }while(1);

    return true;
}

int* YoungTableau::m_Sort(int** tableau, int m, int n, int current_size)
{
    int current_size_copy = current_size;
    int** tableau_copy = new int* [m];
    for(int i=0;i<m;i++)
    {
        tableau_copy[i] = new int[n];
        for(int j=0;j<n;j++)
            tableau_copy[i][j] = tableau[i][j];
    }

    int* array = new int [current_size];

    for(int i=0;current_size_copy>0;i++)
    {
        array[i] = m_ExtractMin(tableau_copy, m, n, current_size_copy);
    }
    
    return array;
}

bool YoungTableau::m_CheckExist(int** tableau, int m, int n, int current_size, int a)
{
    bool result = false;

    if(current_size<=0)
        return false;
    
    //Check from left-down node
    //Ref: https://www.cnblogs.com/shuaiwhu/archive/2011/03/21/2065075.html
    int i = (current_size-1) / n;
    int j=0;
    do
    {
        if(tableau[i][j] == a)
        {
            result = true;
            break;
        }
        else if(tableau[i][j] > a)
        {
            i--;
        }
        else if(tableau[i][j] < a)
        {
            j++;
        }
    }while(i>=0 && j<n);

    return result;
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
        for(int j=0;j<m_size_n;j++)
            m_tableau[i][j] = -1;
    }
}

void YoungTableau::m_Execute()
{
    int choice = -1;
    do
    {
        printf("1. ExtractMin.\n");
        printf("2. Insert.\n");
        printf("3. Sort.\n");
        printf("4. CheckExist.\n");
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                int min = m_ExtractMin(m_tableau, m_size_m, m_size_n, m_current_size);
                printf("Extracted min value is %d\n", min);
                break;
            }
            case 2:
            {
                int i;
                printf("Input a value(>0) insert to YoungTableau.\n");
                cin >> i;
                assert(i>0);
                m_Insert(m_tableau, m_size_m, m_size_n, m_current_size, i);
                break;
            }
            case 3:
            {
                int* array = m_Sort(m_tableau, m_size_m, m_size_n, m_current_size);
                for(int i=0;i<m_current_size;i++)
                    printf("%d ", array[i]);
                printf("\n");
                delete [] array;
                break;
            }
            case 4:
            {
                int i;
                printf("Input a value check whether exsit in YoungTableau.\n");
                cin >> i;
                bool exist = m_CheckExist(m_tableau, m_size_m, m_size_n, m_current_size, i);
                printf("%d %s exsit in YoungTableau.\n", i , exist?"is":"is not");
                break;
            }
        }
        bool result = m_CheckOutput();
        printf("Check output %s\n", result?"successed":"failed");
    }while(choice>0);
    //printf("");
}

void YoungTableau::m_Print()
{
    for(int i=0;i<m_size_m;i++)
    {
        for(int j=0;j<m_size_n;j++)
        {
            printf("%d ", m_tableau[i][j]);
        }
        printf("\n");
    }
}

bool YoungTableau::m_CheckOutput()
{
    bool result = true;
    for(int i=0;i<m_size_m;i++)
    {
        for(int j=0;j<m_size_n;j++)
        {
            printf("%d ", m_tableau[i][j]);
            if(j<m_size_n-2 && m_tableau[i][j+1] != -1 && m_tableau[i][j] > m_tableau[i][j+1])
            {
                result = false;
                break;
            }
            if(i<m_size_m-2 && m_tableau[i+1][j] != -1  && m_tableau[i][j] > m_tableau[i+1][j])
            {
                result = false;
                break;
            }
        }
        printf("\n");
        if(!result)
            break;
    }
    return result;
}