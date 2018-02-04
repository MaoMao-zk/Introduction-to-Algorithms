// Copyright [2017] <MaoMao>

#ifndef _I_RED_BLACK_TREE_TEST_H_
#define _I_RED_BLACK_TREE_TEST_H_

#include "AdvancedCollectionTest.h"
#include "RedBlackTree.hpp"

class RedBlackTreeTest : public AdvancedCollectionTest
{
 public:
    RedBlackTreeTest()
    {
        m_info.id = "A-13-0";
        m_info.name = "RedBlackTree";
    }
    virtual ~RedBlackTreeTest() {}
 protected:
    virtual ICollection<int>* CreatCollection();
    virtual Element<int>* CreatElement();
    virtual void Print();
};

#endif
