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
    //O(m+n)
    int m_ExtractMin(int** tableau, int m, int n, int& current_size);
    //O(m+n)
    bool m_Insert(int** tableau, int m, int n, int& current_size, int a);
    //O(n^3)
    int* m_Sort(int** tableau, int m, int n, int current_size);
    //O(m+n)
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
