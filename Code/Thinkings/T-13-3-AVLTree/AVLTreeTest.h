// Copyright [2017] <MaoMao>

#ifndef _I_AVL_TREE_TEST_H_
#define _I_AVL_TREE_TEST_H_

#include "AdvancedCollectionTest.h"
#include "AVLTree.h"
#include "../../Algorithms/A-12-0-BinarySearchTree/BinarySearchTreeTest.h"

class AVLTreeTest : public BinarySearchTreeTest
{
 public:
    AVLTreeTest()
    {
        m_info.id = "T-13-3";
        m_info.name = "AVLTree";
    }
    virtual ~AVLTreeTest() {}
 protected:
    virtual ICollection* CreatCollection();
    virtual Element* CreatElement();
};

#endif
