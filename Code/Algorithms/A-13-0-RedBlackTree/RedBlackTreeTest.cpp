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
    RedBlackTree<int>* tree = static_cast<RedBlackTree<int>*>(m_pCollection);
    if (tree->root == tree->nil)
    {
        printf("Tree is empty.\n");
        return;
    }

    RedBlackTreeNode<int>* queue[1024];
    int head = 0;
    int tail = 1;
    queue[0] = tree->root;
    while(head != tail)
    {
        int i = head;
        int tmp_tail = tail;
        for(; i < tmp_tail; i++)
        {
            if (queue[i]->left != tree->nil)
            {
                queue[tail] = queue[i]->left;
                tail++;
                if(tail >= 1024)
                    tail = 0;
            }
            if (queue[i]->right != tree->nil)
            {
                queue[tail] = queue[i]->right;
                tail++;
                if(tail >= 1024)
                    tail = 0;
            }
            if(queue[i]->color == RED)
                printf("\033[31m%d\033[0m(%d) ", queue[i]->key, queue[i]->p->key);
            else
                printf("%d(%d) ", queue[i]->key, queue[i]->p->key);
            head++;
        }
        printf("\n");
    }
}
