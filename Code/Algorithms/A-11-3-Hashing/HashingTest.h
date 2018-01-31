// Copyright [2017] <MaoMao>

#ifndef _I_HASHING_TEST_H_
#define _I_HASHING_TEST_H_

#include "Algorithms.h"
#include "Hashing.hpp"

class HashingTest : public Algorithms
{
 public:
    HashingTest()
    {
        m_info.id = "A-11-3";
        m_info.name = "Hashing";
    }
    virtual ~HashingTest() {}
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput() {return true;}
 private:
    Hashing<int> * hash;
};

#endif
