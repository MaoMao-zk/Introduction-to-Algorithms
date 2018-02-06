// Copyright [2017] <MaoMao>

#ifndef _RED_BALCK_TREE_HPP_
#define _RED_BALCK_TREE_HPP_

#include "ICollection.h"

#include <stdint.h>

enum RBTreeColor
{
    BLACK = 0,
    RED = 1
};

struct RedBlackTreeNode : public Element
{
    RBTreeColor color;
    RedBlackTreeNode* p;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;

    RedBlackTreeNode()
    {
        color = RED;
        p = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class RedBlackTree : public IAdvancedCollection
{
 public:
    RedBlackTree();
    virtual ~RedBlackTree();
 public:
    // Return null if not found
    virtual Element* Search(int key);
    virtual void Insert(Element* elm);
    virtual void Delete(Element* elm);
    virtual Element* Minimum();
    virtual Element* Maximum();
    virtual Element* Successor(Element* elm);
    virtual Element* Predecessor(Element* elm);
 private:
    RedBlackTreeNode* MinimumSubTree(RedBlackTreeNode* r);
    Element* MaximumSubTree(RedBlackTreeNode* r);
    void Transplant(RedBlackTreeNode* from, RedBlackTreeNode* to);
    void LeftRotate(RedBlackTreeNode* x);
    void RightRotate(RedBlackTreeNode* y);
    void InsertFixup(RedBlackTreeNode* z);
    void DeleteFixup(RedBlackTreeNode* x);
 public:
    RedBlackTreeNode* root;
    RedBlackTreeNode* nil;
};

#endif
