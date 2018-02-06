// Copyright [2017] <MaoMao>

#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

#include "ICollection.h"

#include <stdint.h>

struct BinaryTreeNode : public Element
{
    BinaryTreeNode* p;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode()
    {
        p = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree : public IAdvancedCollection
{
 public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
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
    BinaryTreeNode* MinimumSubTree(BinaryTreeNode* r);
    Element* MaximumSubTree(BinaryTreeNode* r);
    void Transplant(BinaryTreeNode* from, BinaryTreeNode* to);
 public:
    BinaryTreeNode* root;
};

#endif
