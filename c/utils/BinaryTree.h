#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct BinaryTreeNode_T {
    int val;
    struct BinaryTreeNode_T *left;
    struct BinaryTreeNode_T *right;
} BinaryTree;

BinaryTree *BinaryTreeNodeCreate(int val, BinaryTree *left, BinaryTree *right);
bool BinaryTreeIsBalanced(BinaryTree *tree);
int BinaryTreeHeight(BinaryTree *tree);
