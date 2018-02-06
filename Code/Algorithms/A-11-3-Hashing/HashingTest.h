// Copyright [2017] <MaoMao>

#ifndef _I_HASHING_TEST_H_
#define _I_HASHING_TEST_H_

#include "CollectionTest.h"

class HashingTest : public CollectionTest
{
 public:
    HashingTest()
    {
        m_info.id = "A-11-3";
        m_info.name = "Hashing";
    }
    virtual ~HashingTest() {}
 protected:
    virtual ICollection* CreatCollection();
    virtual Element* CreatElement();
    virtual void Print();
};

#endif
