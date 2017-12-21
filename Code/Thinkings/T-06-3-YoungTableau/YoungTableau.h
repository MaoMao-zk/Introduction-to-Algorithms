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
    void m_Print();
 private:
    int m_size_m;
    int m_size_n;
    int** m_tableau;

    int m_current_size;
    int m_last[2];
};

#endif
