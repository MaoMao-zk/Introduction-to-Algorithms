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

template <class T>
struct RedBlackTreeNode : public Element<T>
{
    RBTreeColor color;
    RedBlackTreeNode<T>* p;
    RedBlackTreeNode<T>* left;
    RedBlackTreeNode<T>* right;

    RedBlackTreeNode()
    {
        color = RED;
        p = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class RedBlackTree : public IAdvancedCollection<T>
{
 public:
    RedBlackTree()
    {
        nil = new RedBlackTreeNode<T>();
        nil->color = BLACK;
    }
    virtual ~RedBlackTree()
    {
        // TODO(MaoMao): delete tree?
    }
 public:
    // Return null if not found
    virtual Element<T>* Search(int key)
    {
        RedBlackTreeNode<T>* p = root;
        while (p != nil && p->key != key)
        {
            if (key < p->key)
                p = p->left;
            else if (key > p->key)
                p = p->right;
        }
        return p;
    }
    virtual void Insert(Element<T>* elm)
    {
        RedBlackTreeNode<T>* pElm = static_cast<RedBlackTreeNode<T>*>(elm);
        RedBlackTreeNode<T>* px = root;
        RedBlackTreeNode<T>* py = nil;

        while (px != nil)
        {
            py = px;
            if (pElm->key < px->key)
                px = px->left;
            else
                px = px->right;
        }

        pElm->p = py;

        // Tree is empty
        if (root == nil)
            root = pElm;
        else if (pElm->key < py->key)
            py->left = pElm;
        else
            py->right = pElm;

        pElm->left = nil;
        pElm->right = nil;
        pElm->color = RED;
        InsertFixup(pElm);
    }
    virtual void Delete(Element<T>* elm)
    {
        RedBlackTreeNode<T>* pElm = static_cast<RedBlackTreeNode<T>*>(elm);
        RBTreeColor originalColor = pElm->color;
        RedBlackTreeNode<T>* lowMovedNode = nil;

        if (pElm->left == nil)
        {
            lowMovedNode = pElm->right;
            Transplant(pElm->right, pElm);
        }
        else if (pElm->right == nil)
        {
            lowMovedNode = pElm->left;
            Transplant(pElm->left, pElm);
        }
        else
        {
            RedBlackTreeNode<T>* min = MinimumSubTree(pElm->right);
            originalColor = min->color;
            lowMovedNode = min->right;
            if (min->p != pElm)
            {
                Transplant(min->right, min);
                min->right = pElm->right;
                pElm->right->p = min;
            }
            Transplant(min, pElm);
            min->left = pElm->left;
            pElm->left->p = min;
            min->color = pElm->color;
        }
        if (originalColor == BLACK)
            DeleteFixup(lowMovedNode);
    }
    virtual Element<T>* Minimum()
    {
        return MinimumSubTree(root);
    }
    virtual Element<T>* Maximum()
    {
        return MaximumSubTree(root);
    }
    virtual Element<T>* Successor(Element<T>* elm)
    {
        RedBlackTreeNode<T>* pElm = static_cast<RedBlackTreeNode<T>*>(elm);

        if (pElm->right != nil)
            return MinimumSubTree(pElm->right);

        while (pElm->p != nil && pElm == pElm->p->right)
            pElm = pElm->p;
        return pElm->p;
    }
    virtual Element<T>* Predecessor(Element<T>* elm)
    {
        RedBlackTreeNode<T>* pElm = static_cast<RedBlackTreeNode<T>*>(elm);

        if (pElm->left != nil)
            return MaximumSubTree(pElm);

        while (pElm->p != nil && pElm == pElm->p->left)
            pElm = pElm->p;
        return pElm->p;
    }
 protected:
    virtual RedBlackTreeNode<T>* MinimumSubTree(RedBlackTreeNode<T>* r)
    {
        RedBlackTreeNode<T>* p = r;
        while (p != nil && p->left != nil)
                p = p->left;
        return p;
    }
    virtual Element<T>* MaximumSubTree(RedBlackTreeNode<T>* r)
    {
        RedBlackTreeNode<T>* p = r;
        while (p != nil && p->right != nil)
                p = p->right;
        return p;
    }
    virtual void Transplant(RedBlackTreeNode<T>* from, RedBlackTreeNode<T>* to)
    {
        // to is root node.
        if (to->p == nil)
            root = static_cast<RedBlackTreeNode<T>*>(from);
        else if (to == to->p->left)
            to->p->left = from;
        else
            to->p->right = from;
        from->p = to->p;
    }
    virtual void LeftRotate(RedBlackTreeNode<T>* x)
    {
        RedBlackTreeNode<T>* y = x->right;
        // y->left go to x->right
        x->right = y->left;
        x->right->p = x;
        // x->p go to y->p
        y->p = x->p;
        if (x->p == nil)
            root = static_cast<RedBlackTreeNode<T>*>(y);
        else if(x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
        // x as y->left
        y->left = x;
        x->p = y;
    }
    virtual void RightRotate(RedBlackTreeNode<T>* y)
    {
        RedBlackTreeNode<T>* x = y->left;
        // x->right go to y->left
        y->left = x->right;
        y->left->p = y;
        // y->p go to x->p
        x->p = y->p;
        if (y->p == nil)
            root = y;
        else if(y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
        // y as x->right
        x->right = y;
        y->p = x;
    }
    virtual void InsertFixup(RedBlackTreeNode<T>* z)
    {
        while (z->p->color == RED)
        {
            if(z->p == z->p->p->left)
            {
                RedBlackTreeNode<T>* y = z->p->p->right;
                if (y->color == RED)
                {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->right)
                    {
                        z = z->p;
                        LeftRotate(z);
                    }
                    z->p->p->color = RED;
                    z->p->color = BLACK;
                    RightRotate(z->p->p);
                }
            }
            else // z->p == z->p->p->right
            {
                RedBlackTreeNode<T>* y = z->p->p->left;
                if(y->color == RED)
                {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->left)
                    {
                        z = z->p;
                        RightRotate(z);
                    }
                    z->p->p->color = RED;
                    z->p->color = BLACK;
                    LeftRotate(z->p->p);
                }
            }
        }
        root->color = BLACK;
    }
    virtual void DeleteFixup(RedBlackTreeNode<T>* x)
    {
        while (x != root && x->color == BLACK)
        {
            if (x == x->p->left)
            {
                RedBlackTreeNode<T>* w = x->p->right;
                // Case 1, change to case 2, 3, 4
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->p->color = RED;
                    LeftRotate(x->p);
                    w = x->p->right;
                }
                // Case 2, w->color == BLACK
                if(w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x = x->p;
                }
                else
                {
                    //Case 3, change to case 4
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        RightRotate(w);
                        w = x->p->right;
                    }
                    //Case 4
                    w->color = x->p->color;
                    x->p->color = BLACK;
                    w->right->color = BLACK;
                    LeftRotate(x->p);
                    x = root;
                }
            }
            else // x == x->p->right
            {
                RedBlackTreeNode<T>* w = x->p->left;
                // Case 1, change to case 2, 3, 4
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->p->color = RED;
                    RightRotate(x->p);
                    w = x->p->left;
                }
                // Case 2, w->color == BLACK
                if(w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x = x->p;
                }
                else
                {
                    //Case 3, change to case 4
                    if (w->left->color == BLACK)
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        LeftRotate(w);
                        w = x->p->left;
                    }
                    //Case 4
                    w->color = x->p->color;
                    x->p->color = BLACK;
                    w->left->color = BLACK;
                    RightRotate(x->p);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
 public:
    RedBlackTreeNode<T>* root;
    RedBlackTreeNode<T>* nil;
};

#endif
