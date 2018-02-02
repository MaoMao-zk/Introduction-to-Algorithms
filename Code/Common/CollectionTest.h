// Copyright [2017] <MaoMao>

#ifndef _I_COLLECTION_TEST_H_
#define _I_COLLECTION_TEST_H_

#include "Algorithms.h"
#include "ICollection.h"

class CollectionTest : public Algorithms
{
 public:
    virtual ~CollectionTest() {}
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 protected:
    virtual ICollection<int>* CreatCollection() = 0;
    virtual Element<int>* CreatElement() = 0;
    virtual void Print() = 0;
 protected:
    ICollection<int>* m_pCollection;
};

#endif
