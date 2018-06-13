// Copyright [2017] <MaoMao>
// Ref: https://articles.leetcode.com/how-to-pretty-print-binary-tree/
// There is reference code, so ignore code standard

#include "RedBlackTreeTest.h"
#include "RedBlackTree.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

ICollection* RedBlackTreeTest::CreatCollection()
{
    return new RedBlackTree();
}

Element* RedBlackTreeTest::CreatElement()
{
    return new RedBlackTreeNode();
}

static string intToString(int val)
{
  stringstream ss;
  ss<<val;
  string str = ss.str();
  return str;
}

static int maxHeight(RedBlackTreeNode *root, RedBlackTreeNode *nil)
{
  if (root == nil)
    return 0;
  else
    return max(maxHeight(root->left, nil), maxHeight(root->right, nil)) + 1;
}

// Print the arm branches (eg, /    \ ) on a line
static void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<RedBlackTreeNode*>& nodesQueue, ostream& out, RedBlackTreeNode *nil) {
  deque<RedBlackTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) != nil ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) != nil ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
static void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<RedBlackTreeNode*>& nodesQueue, ostream& out, RedBlackTreeNode *nil) {
  deque<RedBlackTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << (((*iter) != nil && (*iter)->left != nil) ? setfill('_') : setfill(' '));
    //out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->key) : "");

    if((*iter) == nil)
        out << setw(branchLen+2) << "";
    else
    {
        if ((*iter)->color == BLACK)
            out << setw(branchLen+2) << intToString((*iter)->key);
        else
            out << setw(branchLen+2+strlen("\033[31m")-intToString((*iter)->key).length()) << "\033[31m" << intToString((*iter)->key) << "\033[0m";
    }
    out << (((*iter) != nil && (*iter)->right != nil) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
static void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<RedBlackTreeNode*>& nodesQueue, ostream& out, RedBlackTreeNode *nil) {
  deque<RedBlackTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2));
    if ((*iter) == nil)
        out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << "";
    else
    {
        if ((*iter)->color == BLACK)
            out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << intToString((*iter)->key);
        else
            out << ((i == 0) ? setw(indentSpace+2+strlen("\033[31m")-intToString((*iter)->key).length()) : setw(2*level+2+strlen("\033[31m")-intToString((*iter)->key).length())) << "\033[31m" << intToString((*iter)->key) << "\033[0m";
    }
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
static void printPretty(RedBlackTreeNode *root, int level, int indentSpace, ostream& out, RedBlackTreeNode *nil) {
  int h = maxHeight(root, nil);
  out << "maxHeight: " << h << endl;
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

  deque<RedBlackTreeNode*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out, nil);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out, nil);

    for (int i = 0; i < nodesInThisLevel; i++) {
      RedBlackTreeNode *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode != nil) {
       nodesQueue.push_back(currNode->left);
       nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(nil);
        nodesQueue.push_back(nil);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out, nil);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out, nil);
}

void RedBlackTreeTest::Print()
{
    RedBlackTree* tree = static_cast<RedBlackTree*>(m_pCollection);
    if (tree->root == tree->nil)
    {
        printf("Tree is empty.\n");
        return;
    }

    printPretty(tree->root, 1, 0, cout, tree->nil);
    /*
    RedBlackTreeNode* queue[1024];
    int head = 0;
    int tail = 1;
    queue[0] = tree->root;
    while (head != tail)
    {
        int i = head;
        int tmp_tail = tail;
        for (; i < tmp_tail; i++)
        {
            if (queue[i]->left != tree->nil)
            {
                queue[tail] = queue[i]->left;
                tail++;
                if (tail >= 1024)
                    tail = 0;
            }
            if (queue[i]->right != tree->nil)
            {
                queue[tail] = queue[i]->right;
                tail++;
                if (tail >= 1024)
                    tail = 0;
            }
            if (queue[i]->color == RED)
                printf("\033[31m%d\033[0m(%d) ", queue[i]->key, queue[i]->p->key);
            else
                printf("%d(%d) ", queue[i]->key, queue[i]->p->key);
            head++;
        }
        printf("\n");
    }*/
}

bool RedBlackTreeTest::m_CheckOutput()
{
    RedBlackTree* p = static_cast<RedBlackTree*>(m_pCollection);
    Element* current = p->Minimum();
    Element* next = p->nil;
    while (current != p->nil)
    {
        next = p->Successor(current);
        if (next != p->nil && next->key < current->key)
        {
            fprintf(stderr, "next->key(%d) < current->key(%d)\n", next->key, current->key);
            return false;
        }
        current = next;
    }

    if (p->root != p->nil)
    {
        // root color should be black
        if (p->root->color != BLACK)
        {
            fprintf(stderr, "p->root->key(%d) color is not BLACK.\n", p->root->key);
            return false;
        }

        // Get left black height
        RedBlackTreeNode* current = p->root;
        int leftBH = 0;
        while (current != p->nil)
        {
            if (current->color == BLACK)
                leftBH++;
            current = current->left;
        }
        return DFSCheck(p, p->root, 0, leftBH);
    }
    return true;
}

bool RedBlackTreeTest::DFSCheck(RedBlackTree* tree, RedBlackTreeNode* node, int currentBH, int bhForCheck)
{
    // leave node
    if (node == tree->nil)
    {
        if (currentBH != bhForCheck)
        {
            fprintf(stderr, "currentBH(%d) != bhForCheck(%d).\n", currentBH, bhForCheck);
            return false;
        }
        else
            return true;
    }
    if (node->color == BLACK)
        currentBH++;
    else if (node->left->color == RED || node->right->color == RED)
    {
        fprintf(stderr, "node(%d) is RED, node->left->color = %d, node->right->color = %d.\n", node->key, node->left->color, node->right->color);
        return false;
    }
    if (!DFSCheck(tree, node->left, currentBH, bhForCheck))
        return false;
    if (!DFSCheck(tree, node->right, currentBH, bhForCheck))
        return false;
    return true;
}
