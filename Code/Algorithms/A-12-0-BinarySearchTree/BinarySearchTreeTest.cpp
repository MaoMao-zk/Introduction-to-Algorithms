// Copyright [2017] <MaoMao>

#include "BinarySearchTreeTest.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

ICollection* BinarySearchTreeTest::CreatCollection()
{
    return new BinarySearchTree();
}

Element* BinarySearchTreeTest::CreatElement()
{
    return new BinaryTreeNode();
}

void BinarySearchTreeTest::Print()
{
    BinarySearchTree* p = static_cast<BinarySearchTree*>(m_pCollection);
    Element* node = p->Minimum();
    while (node != nullptr)
    {
        printf("%d ", node->key);
        node = p->Successor(node);
    }
    printf("\n");
}
