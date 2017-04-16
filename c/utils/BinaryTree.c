#include "BinaryTree.h"

#define BALANCE_HEIGHT_DIFFERENCE_MAX 1
#define UNBALANCED -1
#define MAX(a,b) (((a)>(b))?(a):(b))

BinaryTree *BinaryTreeNodeCreate(int val, BinaryTree *left, BinaryTree *right) {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    tree->val = val;
    tree->left = left;
    tree->right = right;

    return tree;
}

int BinaryTreeHeight(BinaryTree *tree) {

    if (tree == NULL)
        return 0;

    int heightLeft = BinaryTreeHeight(tree->left);
    int heightRight = BinaryTreeHeight(tree->right);

    return 1 + MAX(heightLeft, heightRight);
}

bool BinaryTreeIsBalanced(BinaryTree *tree) {

    if (tree == NULL) {
        return true;
    }

    int heightLeft = BinaryTreeHeight(tree->left);
    int heightRight = BinaryTreeHeight(tree->right);

    if (abs(heightLeft - heightRight) > 1) {
        return false;
    }

    return BinaryTreeIsBalanced(tree->left) && BinaryTreeIsBalanced(tree->right);
}
