// Copyright [2017] <MaoMao>

#include "ActivityChoice.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

extern int activity_choice(int(*activity)[2], int num_sum, int*&result);

static int case_in_book[11][2] = {
    { 1, 4},
    { 3, 5 },
    { 0, 6 },
    { 5, 7 },
    { 3, 9 },
    { 5, 9 },
    { 6, 10 },
    { 8, 11 },
    { 8, 12 },
    { 2, 14 },
    { 12, 16 },
};

extern char* longest_common_subsequence(char* X, char* Y);

ActivityChoice::ActivityChoice()
{
    m_info.id = "A-16-1";
    m_info.name = "ActivityChoice";

    activity = case_in_book;
    num = 11;

    result_activity = nullptr;
}

ActivityChoice::~ActivityChoice()
{
    if (result_activity)
    {
        delete []result_activity;
        result_activity = nullptr;
    }
}

void ActivityChoice::m_BuildInput()
{
    for (int i = 0; i < num; i++)
        printf("| %2d ", activity[i][0]);
    printf("|\n");
    for (int i = 0; i < num; i++)
        printf("| %2d ", activity[i][1]);
    printf("|\n");
}

void ActivityChoice::m_Execute()
{
    result_num = activity_choice(activity, num, result_activity);
}

bool ActivityChoice::m_CheckOutput()
{
    printf("Result(%d): \n", result_num);
    for (int i = 0; i < result_num; i++)
        printf("<%d,%d> ", activity[result_activity[i]][0], activity[result_activity[i]][1]);
    printf("\n");
    return true;
}
