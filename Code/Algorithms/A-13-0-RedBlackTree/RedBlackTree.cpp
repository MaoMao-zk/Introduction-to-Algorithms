// Copyright [2017] <MaoMao>

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
    nil = new RedBlackTreeNode();
    nil->color = BLACK;
    root = nil;
}

RedBlackTree::~RedBlackTree()
{
    // TODO(MaoMao): delete tree?
}

Element* RedBlackTree::Search(int key)
{
    RedBlackTreeNode* p = root;
    while (p != nil && p->key != key)
    {
        if (key < p->key)
            p = p->left;
        else if (key > p->key)
            p = p->right;
    }
    return p;
}

void RedBlackTree::Insert(Element* elm)
{
    RedBlackTreeNode* pElm = static_cast<RedBlackTreeNode*>(elm);
    RedBlackTreeNode* px = root;
    RedBlackTreeNode* py = nil;

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

void RedBlackTree::Delete(Element* elm)
{
    RedBlackTreeNode* pElm = static_cast<RedBlackTreeNode*>(elm);
    RBTreeColor originalColor = pElm->color;
    RedBlackTreeNode* lowMovedNode = nil;

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
        RedBlackTreeNode* min = MinimumSubTree(pElm->right);
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

Element* RedBlackTree::Minimum()
{
    return MinimumSubTree(root);
}

Element* RedBlackTree::Maximum()
{
    return MaximumSubTree(root);
}

Element* RedBlackTree::Successor(Element* elm)
{
    RedBlackTreeNode* pElm = static_cast<RedBlackTreeNode*>(elm);

    if (pElm->right != nil)
        return MinimumSubTree(pElm->right);

    while (pElm->p != nil && pElm == pElm->p->right)
        pElm = pElm->p;
    return pElm->p;
}

Element* RedBlackTree::Predecessor(Element* elm)
{
    RedBlackTreeNode* pElm = static_cast<RedBlackTreeNode*>(elm);

    if (pElm->left != nil)
        return MaximumSubTree(pElm);

    while (pElm->p != nil && pElm == pElm->p->left)
        pElm = pElm->p;
    return pElm->p;
}

RedBlackTreeNode* RedBlackTree::MinimumSubTree(RedBlackTreeNode* r)
{
    RedBlackTreeNode* p = r;
    while (p != nil && p->left != nil)
            p = p->left;
    return p;
}

Element* RedBlackTree::MaximumSubTree(RedBlackTreeNode* r)
{
    RedBlackTreeNode* p = r;
    while (p != nil && p->right != nil)
            p = p->right;
    return p;
}

void RedBlackTree::Transplant(RedBlackTreeNode* from, RedBlackTreeNode* to)
{
    // to is root node.
    if (to->p == nil)
        root = static_cast<RedBlackTreeNode*>(from);
    else if (to == to->p->left)
        to->p->left = from;
    else
        to->p->right = from;
    from->p = to->p;
}

void RedBlackTree::LeftRotate(RedBlackTreeNode* x)
{
    RedBlackTreeNode* y = x->right;
    // y->left go to x->right
    x->right = y->left;
    x->right->p = x;
    // x->p go to y->p
    y->p = x->p;
    if (x->p == nil)
        root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    // x as y->left
    y->left = x;
    x->p = y;
}

void RedBlackTree::RightRotate(RedBlackTreeNode* y)
{
    RedBlackTreeNode* x = y->left;
    // x->right go to y->left
    y->left = x->right;
    y->left->p = y;
    // y->p go to x->p
    x->p = y->p;
    if (y->p == nil)
        root = x;
    else if (y == y->p->left)
        y->p->left = x;
    else
        y->p->right = x;
    // y as x->right
    x->right = y;
    y->p = x;
}

void RedBlackTree::InsertFixup(RedBlackTreeNode* z)
{
    while (z->p->color == RED)
    {
        if (z->p == z->p->p->left)
        {
            RedBlackTreeNode* y = z->p->p->right;
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
        else  // z->p == z->p->p->right
        {
            RedBlackTreeNode* y = z->p->p->left;
            if (y->color == RED)
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

void RedBlackTree::DeleteFixup(RedBlackTreeNode* x)
{
    while (x != root && x->color == BLACK)
    {
        if (x == x->p->left)
        {
            RedBlackTreeNode* w = x->p->right;
            // Case 1, change to case 2, 3, 4
            if (w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                LeftRotate(x->p);
                w = x->p->right;
            }
            // Case 2, w->color == BLACK
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                // Case 3, change to case 4
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    RightRotate(w);
                    w = x->p->right;
                }
                // Case 4
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                LeftRotate(x->p);
                x = root;
            }
        }
        else  // x == x->p->right
        {
            RedBlackTreeNode* w = x->p->left;
            // Case 1, change to case 2, 3, 4
            if (w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                RightRotate(x->p);
                w = x->p->left;
            }
            // Case 2, w->color == BLACK
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                // Case 3, change to case 4
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    LeftRotate(w);
                    w = x->p->left;
                }
                // Case 4
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
