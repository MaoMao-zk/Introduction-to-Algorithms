// Copyright [2017] <MaoMao>

#ifndef _I_RED_BLACK_TREE_TEST_H_
#define _I_RED_BLACK_TREE_TEST_H_

#include "AdvancedCollectionTest.h"
#include "RedBlackTree.h"

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
    virtual ICollection* CreatCollection();
    virtual Element* CreatElement();
    virtual void Print();
    virtual bool m_CheckOutput();
 private:
    bool DFSCheck(RedBlackTree* tree, RedBlackTreeNode* node, int currentBH, int bhForCheck);
};

#endif
