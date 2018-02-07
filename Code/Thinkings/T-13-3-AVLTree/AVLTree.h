// Copyright [2017] <MaoMao>

#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include "ICollection.h"
#include "../../Algorithms/A-12-0-BinarySearchTree/BinarySearchTree.h"

#include <stdint.h>

struct AVLTreeNode : public BinaryTreeNode
{
    int height;

    AVLTreeNode() : BinaryTreeNode()
    {
        height = 0;
    }
};

class AVLTree : public BinarySearchTree
{
 public:
    AVLTree() {}
    virtual ~AVLTree();
 public:
    virtual void Insert(Element* elm);
    virtual void Delete(Element* elm);
 protected:
    void AdjustFrom(BinaryTreeNode* x);
    void LeftRotate(BinaryTreeNode* x);
    void RightRotate(BinaryTreeNode* y);
    int Height(Element* elm);
    void SetHeight(Element* elm, int h);
    void ReCalculateHeight(BinaryTreeNode* elm);
};

#endif
