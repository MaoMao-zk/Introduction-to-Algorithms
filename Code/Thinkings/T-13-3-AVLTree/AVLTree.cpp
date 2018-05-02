// Copyright [2017] <MaoMao>

#include "AVLTree.h"
#include <algorithm>

AVLTree::~AVLTree()
{
    // TODO(MaoMao): delete tree?
}

void AVLTree::Insert(Element* elm)
{
    BinaryTreeNode* pElm = static_cast<BinaryTreeNode*>(elm);

    BinarySearchTree::Insert(elm);

    AdjustFrom(pElm);
}

void AVLTree::Delete(Element* elm)
{
    BinaryTreeNode* pElm = static_cast<BinaryTreeNode*>(elm);
    BinaryTreeNode* adjustFromNode = nullptr;

    if (pElm->left == nullptr)
    {
        adjustFromNode = pElm->p;
        Transplant(pElm->right, pElm);
    }
    else if (pElm->right == nullptr)
    {
        adjustFromNode = pElm->p;
        Transplant(pElm->left, pElm);
    }
    else
    {
        BinaryTreeNode* min = MinimumSubTree(pElm->right);
        if (min == pElm->right)
            adjustFromNode = min;
        else
            adjustFromNode = min->p;
        if (min->p != pElm)
        {
            Transplant(min->right, min);
            min->right = pElm->right;
            pElm->right->p = min;
        }
        Transplant(min, pElm);
        min->left = pElm->left;
        pElm->left->p = min;
    }
    AdjustFrom(adjustFromNode);
}

void AVLTree::AdjustFrom(BinaryTreeNode* x)
{
    while (x != nullptr)
    {
        if (x != nullptr)
        {
            // Left heavy
            if ((Height(x->left) - Height(x->right)) >= 2)
            {
                BinaryTreeNode* y = x->left;
                if (Height(y->left) >= Height(y->right))
                {
                    RightRotate(x);
                    ReCalculateHeight(x);
                    x = y;
                }
                else
                {
                    BinaryTreeNode* z = y->right;
                    LeftRotate(y);
                    RightRotate(x);
                    ReCalculateHeight(x);
                    ReCalculateHeight(y);
                    x = z;
                }
            }
            // Right heavy
            else if ((Height(x->right) - Height(x->left)) >= 2)
            {
                BinaryTreeNode* y = x->right;
                if (Height(y->right) >= Height(y->left))
                {
                    LeftRotate(x);
                    ReCalculateHeight(x);
                    x = y;
                }
                else
                {
                    BinaryTreeNode* z = y->left;
                    RightRotate(y);
                    LeftRotate(x);
                    ReCalculateHeight(x);
                    ReCalculateHeight(y);
                    x = z;
                }
            }
        }
        ReCalculateHeight(x);
        x = x->p;
    }
}

void AVLTree::LeftRotate(BinaryTreeNode* x)
{
    BinaryTreeNode* y = x->right;
    // y->left go to x->right
    x->right = y->left;
    if (y->left != nullptr)
        y->left->p = x;
    // x->p go to y->p
    y->p = x->p;
    if (x->p == nullptr)
        root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    // x as y->left
    y->left = x;
    x->p = y;
}

void AVLTree::RightRotate(BinaryTreeNode* y)
{
    BinaryTreeNode* x = y->left;
    // x->right go to y->left
    y->left = x->right;
    if (x->right != nullptr)
        x->right->p = y;
    // y->p go to x->p
    x->p = y->p;
    if (y->p == nullptr)
        root = x;
    else if (y == y->p->left)
        y->p->left = x;
    else
        y->p->right = x;
    // y as x->right
    x->right = y;
    y->p = x;
}

int AVLTree::Height(Element* elm)
{
    if (elm == nullptr)
        return 0;
    AVLTreeNode* pElm = static_cast<AVLTreeNode*>(elm);
    return pElm->height;
}

void AVLTree::SetHeight(Element* elm, int h)
{
    AVLTreeNode* pElm = static_cast<AVLTreeNode*>(elm);
    pElm->height = h;
}

void AVLTree::ReCalculateHeight(BinaryTreeNode* elm)
{
    int leftHeight = Height(elm->left);
    int rightHeight = Height(elm->right);

    SetHeight(elm, std::max(leftHeight, rightHeight) + 1);
}
