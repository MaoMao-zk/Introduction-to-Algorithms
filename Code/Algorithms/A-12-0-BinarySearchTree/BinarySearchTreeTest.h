// Copyright [2017] <MaoMao>

#ifndef _I_BINARY_SEARCH_TREE_TEST_H_
#define _I_BINARY_SEARCH_TREE_TEST_H_

#include "AdvancedCollectionTest.h"
#include "BinarySearchTree.h"

class BinarySearchTreeTest : public AdvancedCollectionTest
{
 public:
    BinarySearchTreeTest()
    {
        m_info.id = "A-12-0";
        m_info.name = "BinarySearchTree";
    }
    virtual ~BinarySearchTreeTest() {}
 protected:
    virtual ICollection* CreatCollection();
    virtual Element* CreatElement();
    virtual void Print();
};

#endif
