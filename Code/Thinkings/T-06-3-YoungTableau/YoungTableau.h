// Copyright [2017] <MaoMao>

#ifndef _YOUNG_TABLEAU_H_
#define _YOUNG_TABLEAU_H_

#include "Algorithms.h"

class YoungTableau : public Algorithms
{
 public:
    YoungTableau();
    virtual ~YoungTableau();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    // O(m+n)
    // 1. Remove first data as the min value
    // 2. Move last data to first position
    // 3. Do MIN-HEAPIFY to first value, right node and down node as it's child node
    int m_ExtractMin(int** tableau, int m, int n, int& current_size);
    // O(m+n)
    // 1. Set insert value to last position
    // 2. Do MIN-HEAP-INSERT, left node and up node as it's parent
    bool m_Insert(int** tableau, int m, int n, int& current_size, int a);
    // O(n^3)
    // 1. Copy tableau
    // 2. Do m_ExtractMin to extract all data
    int* m_Sort(int** tableau, int m, int n, int current_size);
    // O(m+n)
    // 1. Check from left-down node
    // 2. If bigger than checked value, check to up node
    // 3. If smaller than checked value, check to right node
    // 4. If same with checked value, found!
    bool m_CheckExist(int** tableau, int m, int n, int current_size, int a);
 private:
    void m_Print();
 private:
    int m_size_m;
    int m_size_n;
    int** m_tableau;

    int m_current_size;
    int m_last[2];
};

#endif
