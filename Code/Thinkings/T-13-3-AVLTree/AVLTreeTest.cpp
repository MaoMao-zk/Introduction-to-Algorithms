// Copyright [2017] <MaoMao>
// Ref: https://articles.leetcode.com/how-to-pretty-print-binary-tree/
// There is reference code, so ignore code standard

#include "AVLTreeTest.h"
#include "AVLTree.h"

using namespace std;

ICollection* AVLTreeTest::CreatCollection()
{
    return new AVLTree();
}

Element* AVLTreeTest::CreatElement()
{
    return new AVLTreeNode();
}
