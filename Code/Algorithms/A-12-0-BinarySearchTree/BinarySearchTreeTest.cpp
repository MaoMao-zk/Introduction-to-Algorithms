// Copyright [2017] <MaoMao>

#include "BinarySearchTreeTest.h"
#include "BinarySearchTree.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

ICollection<int>* BinarySearchTreeTest::CreatCollection()
{
    return new BinarySearchTree<int>();
}

Element<int>* BinarySearchTreeTest::CreatElement()
{
    return new BinaryTreeNode<int>();
}

void BinarySearchTreeTest::Print()
{
    BinarySearchTree<int>* p = static_cast<BinarySearchTree<int>*>(m_pCollection);
    Element<int>* node = p->Minimum();
    while (node != nullptr)
    {
        printf("%d ", node->key);
        node = p->Successor(node);
    }
    printf("\n");
}
