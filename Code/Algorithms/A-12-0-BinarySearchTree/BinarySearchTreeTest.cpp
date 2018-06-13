// Copyright [2017] <MaoMao>
// Ref: https://articles.leetcode.com/how-to-pretty-print-binary-tree/
// There is reference code, so ignore code standard

#include "BinarySearchTreeTest.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

ICollection* BinarySearchTreeTest::CreatCollection()
{
    return new BinarySearchTree();
}

Element* BinarySearchTreeTest::CreatElement()
{
    return new BinaryTreeNode();
}

static string intToString(int val)
{
  stringstream ss;
  ss<<val;
  string str = ss.str();
  return str;
}

static int maxHeight(BinaryTreeNode *root)
{
  if (root == nullptr)
    return 0;
  else
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

// Print the arm branches (eg, /    \ ) on a line
static void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTreeNode*>& nodesQueue, ostream& out) {
  deque<BinaryTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
static void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTreeNode*>& nodesQueue, ostream& out) {
  deque<BinaryTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->key) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
static void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BinaryTreeNode*>& nodesQueue, ostream& out) {
  deque<BinaryTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->key) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
static void printPretty(BinaryTreeNode *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

  deque<BinaryTreeNode*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      BinaryTreeNode *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
       nodesQueue.push_back(currNode->left);
       nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(nullptr);
        nodesQueue.push_back(nullptr);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

void BinarySearchTreeTest::Print()
{
    BinarySearchTree* p = static_cast<BinarySearchTree*>(m_pCollection);
    printPretty(p->root, 1, 0, cout);
    /*
    Element* node = p->Minimum();
    while (node != nullptr)
    {
        printf("%d ", node->key);
        node = p->Successor(node);
    }
    printf("\n");*/
}

bool BinarySearchTreeTest::m_CheckOutput()
{
    if (!AdvancedCollectionTest::m_CheckOutput())
        return false;

    BinarySearchTree* p = static_cast<BinarySearchTree*>(m_pCollection);
    deque<BinaryTreeNode*> nodesQueue;
    if (p->root != nullptr)
    {
        nodesQueue.push_back(p->root);
        while (!nodesQueue.empty())
        {
            BinaryTreeNode* node = nodesQueue.front();
            if (node->left != nullptr)
            {
                if (node->left->key > node->key)
                {
                    fprintf(stderr, "node->left->key(%d) > node->key(%d)\n", node->left->key, node->key);
                    return false;
                }
                nodesQueue.push_back(node->left);
            }
            if (node->right != nullptr)
            {
                if (node->right->key < node->key)
                {
                    fprintf(stderr, "node->right->key(%d) < node->key(%d)\n", node->right->key, node->key);
                    return false;
                }
                nodesQueue.push_back(node->right);
            }
            nodesQueue.pop_front();
        }
    }
    return true;
}
