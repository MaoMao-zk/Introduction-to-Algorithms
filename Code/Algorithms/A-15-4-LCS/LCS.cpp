// Copyright [2017] <MaoMao>

#include "LCS.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

static const char* testX = "ABCBDAB";
static const char* testY = "BDCABA";

extern char* longest_common_subsequence(char* X, char* Y);

LCS::LCS()
{
    m_info.id = "A-15-4";
    m_info.name = "LCS(longest common subsequence)";

    strX = nullptr;
    strY = nullptr;
    strZ = nullptr;
}

LCS::~LCS()
{
    if (strX != nullptr)
        delete[] strX;

    if (strY != nullptr)
        delete[] strY;

    if (strZ != nullptr)
        delete[] strZ;
}

void LCS::m_BuildInput()
{
    strX = new char[strlen(testX) + 1];
    strncpy(strX, testX, strlen(testX));
    strX[strlen(testX)] = '\0';

    strY = new char[strlen(testY) + 1];
    strncpy(strY, testY, strlen(testY));
    strY[strlen(testY)] = '\0';
}

void LCS::m_Execute()
{
    strZ = longest_common_subsequence(strX, strY);
}

bool LCS::m_CheckOutput()
{
    printf("CLS of %s and %s is %s\n", strX, strY, strZ);
    return true;
}
