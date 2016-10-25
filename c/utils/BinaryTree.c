#include "BinaryTree.h"

#define BALANCE_HEIGHT_DIFFERENCE_MAX 1
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
    if (heightLeft == -1) {
        return -1;
    }

    int heightRight = BinaryTreeHeight(tree->right);
    if (heightRight == -1) {
        return -1;
    }

    int difference = abs(heightRight - heightLeft)
    if (difference > BALANCE_HEIGHT_DIFFERENCE_MAX) {
        return -1;
    }

    return 1 + MAX(heightLeft, heightRight);
}

bool BinaryTreeIsBalanced(BinaryTree *tree) {

    return BinaryTreeHeight(tree) != -1;
}
