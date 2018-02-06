// Copyright [2017] <MaoMao>

#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    // TODO(MaoMao): delete tree?
}

Element* BinarySearchTree::Search(int key)
{
    BinaryTreeNode* p = root;
    while (p != nullptr && p->key != key)
    {
        if (key < p->key)
            p = p->left;
        else if (key > p->key)
            p = p->right;
    }
    return p;
}

void BinarySearchTree::Insert(Element* elm)
{
    BinaryTreeNode* pElm = static_cast<BinaryTreeNode*>(elm);
    BinaryTreeNode* px = root;
    BinaryTreeNode* py = nullptr;

    while (px != nullptr)
    {
        py = px;
        if (pElm->key < px->key)
            px = px->left;
        else
            px = px->right;
    }

    pElm->p = py;

    // Tree is empty
    if (root == nullptr)
        root = pElm;
    else if (pElm->key < py->key)
        py->left = pElm;
    else
        py->right = pElm;
}

void BinarySearchTree::Delete(Element* elm)
{
    BinaryTreeNode* pElm = static_cast<BinaryTreeNode*>(elm);

    // If delete node has only 1 child / no child,
    // Transplant child to delete node place directly
    if (pElm->left == nullptr)
        Transplant(pElm->right, pElm);
    else if (pElm->right == nullptr)
        Transplant(pElm->left, pElm);
    else
    {
        /*
        // If delete node has 2 children, found the min node of right child tree
        // Case 1. Min node is the root node of right child tree.
        // 
        //         Transplant the min node to delete node place, 
        //           and get the left child of delete node
        // 
        //         ○                   ○
        //        / \                 / \ 
        //       ●                  [○]     
        //      / \         ->      / \    
        //        [○]                  ○    
        //          \     
        //           ○       
        // 
        // Case 2. Min node is not the root node of right child tree.
        // 
        //         1. Transplant the right child of min node to min node place,
        //              and min node get the right child of delete node
        //         2. Same with Case 1.
        // 
        //         ○                ○                        ○
        //        / \              / \                      / \ 
        //       ●                ●      [○]              [○] 
        //      / \      -1->    /         \      -2->    / \ 
        //         ○                        ○                ○ 
        //        / \                      / \              / \  
        //      [○]  ○                    ○   ○            ○   ○ 
        //        \                
        //         ○                
        */
        BinaryTreeNode* min = MinimumSubTree(pElm->right);
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
}

Element* BinarySearchTree::Minimum()
{
    return MinimumSubTree(root);
}

Element* BinarySearchTree::Maximum()
{
    return MaximumSubTree(root);
}

Element* BinarySearchTree::Successor(Element* elm)
{
    BinaryTreeNode* pElm = static_cast<BinaryTreeNode*>(elm);

    /*
    //     ○
    //    / \ 
    //   ●
    //  / \ 
    //     ○
    //    / \ 
    //  [○]
    // If elm(●) has right child, successor will be [○].
    // [○] is the mininum node of sub tree that right child as root node.
    */
    if (pElm->right != nullptr)
        return MinimumSubTree(pElm->right);

    /*
    //    [○]
    //    / \ 
    //   ○
    //  / \ 
    //     ●
    //    / 
    // If elm(●) has no right child, successor will be [○].
    // [○] is the parent^n of ●, that parent^n-1 is the left child of parent^n
    // If not found this kind node, means ● is biggest node, return nil
    */
    while (pElm->p != nullptr && pElm == pElm->p->right)
        pElm = pElm->p;
    return pElm->p;
}

Element* BinarySearchTree::Predecessor(Element* elm)
{
    BinaryTreeNode* pElm = static_cast<BinaryTreeNode*>(elm);

    if (pElm->left != nullptr)
        return MaximumSubTree(pElm);

    while (pElm->p != nullptr && pElm == pElm->p->left)
        pElm = pElm->p;
    return pElm->p;
}

BinaryTreeNode* BinarySearchTree::MinimumSubTree(BinaryTreeNode* r)
{
    BinaryTreeNode* p = r;
    while (p != nullptr && p->left != nullptr)
            p = p->left;
    return p;
}

Element* BinarySearchTree::MaximumSubTree(BinaryTreeNode* r)
{
    BinaryTreeNode* p = r;
    while (p != nullptr && p->right != nullptr)
            p = p->right;
    return p;
}

void BinarySearchTree::Transplant(BinaryTreeNode* from, BinaryTreeNode* to)
{
    // to is root node.
    if (to->p == nullptr)
        root = from;
    else if (to == to->p->left)
        to->p->left = from;
    else
        to->p->right = from;
    if (from != nullptr)
        from->p = to->p;
}
