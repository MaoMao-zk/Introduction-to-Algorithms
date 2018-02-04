// Copyright [2017] <MaoMao>

#include "RedBlackTreeTest.h"
#include "RedBlackTree.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

ICollection<int>* RedBlackTreeTest::CreatCollection()
{
    return new RedBlackTree<int>();
}

Element<int>* RedBlackTreeTest::CreatElement()
{
    return new RedBlackTreeNode<int>();
}

void RedBlackTreeTest::Print()
{
    RedBlackTree<int>* p = static_cast<RedBlackTree<int>*>(m_pCollection);
    Element<int>* node = p->Minimum();
    while (node != nullptr)
    {
        printf("%d ", node->key);
        node = p->Successor(node);
    }
    printf("\n");
}
