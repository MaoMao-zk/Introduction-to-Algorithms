// Copyright [2017] <MaoMao>

#ifndef _RANDOMIZED_SELECT_H_
#define _RANDOMIZED_SELECT_H_

#include "Algorithms.h"

class RandomizedSelect : public Algorithms
{
 public:
    RandomizedSelect();
    virtual ~RandomizedSelect();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    int m_size;
    int* m_array;
    int m_select;
    int m_selected;
};

#endif
