// Copyright [2017] <MaoMao>

#ifndef _I_ADVANCED_COLLECTION_TEST_H_
#define _I_ADVANCED_COLLECTION_TEST_H_

#include "CollectionTest.h"

class AdvancedCollectionTest : public CollectionTest
{
 public:
    virtual ~AdvancedCollectionTest() {}
 protected:
    virtual void m_Execute();
    virtual bool m_CheckOutput();
};

#endif
