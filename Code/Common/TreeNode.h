// Copyright [2017] <MaoMao>

#ifndef _I_TREE_NODE_H_
#define _I_TREE_NODE_H_

#include "ICollection.h"

template <class T>
struct BinaryTreeNode : public Element<T>
{
    BinaryTreeNode<T>* p;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode()
    {
        p = nullptr;
        left = nullptr;
        right = nullptr;
    }
};


#endif
