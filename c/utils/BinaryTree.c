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

    if (tree == NULL) {
        return 0;
    }

    int heightLeft = BinaryTreeHeight(tree->left);
    if (heightLeft == UNBALANCED) {
        return UNBALANCED;
    }

    int heightRight = BinaryTreeHeight(tree->right);
    if (heightRight == UNBALANCED) {
        return UNBALANCED;
    }

    int difference = abs(heightRight - heightLeft);
    if (difference > BALANCE_HEIGHT_DIFFERENCE_MAX) {
        return UNBALANCED;
    }

    return 1 + MAX(heightLeft, heightRight);
}

bool BinaryTreeIsBalanced(BinaryTree *tree) {

    return BinaryTreeHeight(tree) != UNBALANCED;
}
