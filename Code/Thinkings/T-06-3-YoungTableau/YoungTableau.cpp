// Copyright [2017] <MaoMao>

#include "YoungTableau.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

extern int young_tableau_extract_min(int** tableau, int m, int n, int* current_size);
extern bool young_tableau_insert(int** tableau, int m, int n, int* current_size, int a);
extern int* young_tableau_sort(int** tableau, int m, int n, int current_size);
extern bool young_tableau_check_exist(int** tableau, int m, int n, int current_size, int a);

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
    if (m_tableau != NULL)
    {
        for (int i = 0; i < m_size_m; i++)
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
    assert(m_size_m > 0);
    assert(m_size_n > 0);

    m_tableau = new int*[m_size_m];
    for (int i = 0; i < m_size_m; i++)
    {
        m_tableau[i] = new int[m_size_n];
        for (int j = 0; j < m_size_n; j++)
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
        switch (choice)
        {
            case 1:
            {
                int min = young_tableau_extract_min(m_tableau, m_size_m, m_size_n, &m_current_size);
                printf("Extracted min value is %d\n", min);
                break;
            }
            case 2:
            {
                int i;
                printf("Input a value(>0) insert to YoungTableau.\n");
                cin >> i;
                assert(i > 0);
                young_tableau_insert(m_tableau, m_size_m, m_size_n, &m_current_size, i);
                break;
            }
            case 3:
            {
                int* array = young_tableau_sort(m_tableau, m_size_m, m_size_n, m_current_size);
                for (int i = 0; i < m_current_size; i++)
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
                bool exist = young_tableau_check_exist(m_tableau, m_size_m, m_size_n, m_current_size, i);
                printf("%d %s exsit in YoungTableau.\n", i , exist?"is":"is not");
                break;
            }
        }
        bool result = m_CheckOutput();
        printf("Check output %s\n", result?"successed":"failed");
    }while(choice > 0);
    // printf("");
}

void YoungTableau::m_Print()
{
    for (int i = 0; i < m_size_m; i++)
    {
        for (int j = 0; j < m_size_n; j++)
        {
            printf("%d ", m_tableau[i][j]);
        }
        printf("\n");
    }
}

bool YoungTableau::m_CheckOutput()
{
    bool result = true;
    for (int i = 0; i < m_size_m; i++)
    {
        for (int j = 0; j < m_size_n; j++)
        {
            printf("%d ", m_tableau[i][j]);
            if (j < m_size_n-2 && m_tableau[i][j+1] != -1 && m_tableau[i][j] > m_tableau[i][j+1])
            {
                result = false;
                break;
            }
            if (i < m_size_m-2 && m_tableau[i+1][j] != -1  && m_tableau[i][j] > m_tableau[i+1][j])
            {
                result = false;
                break;
            }
        }
        printf("\n");
        if (!result)
            break;
    }
    return result;
}
