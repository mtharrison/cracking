#include "BinaryTree.h"

#define BALANCE_HEIGHT_DIFFERENCE_MAX 1
#define UNBALANCED_TREE -1
#define MAX(a,b) (((a)>(b))?(a):(b))

BinaryTree *BinaryTreeNodeCreate(int val, BinaryTree *left, BinaryTree *right) {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    tree->val = val;
    tree->left = left;
    tree->right = right;

    return tree;
}

// The following functions are inefficient and require O(N) space and O(N^2)
// the key observation is that we can check in BinaryTreeHeight if we have an
// unbalanced tree and return early with a special constant if that is the case
//
// int BinaryTreeHeight(BinaryTree *tree) {
//
//     if (tree == NULL)
//         return 0;
//
//     int heightLeft = BinaryTreeHeight(tree->left);
//     int heightRight = BinaryTreeHeight(tree->right);
//
//     return 1 + MAX(heightLeft, heightRight);
// }
//
// bool BinaryTreeIsBalanced(BinaryTree *tree) {
//
//     if (tree == NULL) {
//         return true;
//     }
//
//     int heightLeft = BinaryTreeHeight(tree->left);
//     int heightRight = BinaryTreeHeight(tree->right);
//
//     if (abs(heightLeft - heightRight) > 1) {
//         return false;
//     }
//
//     return BinaryTreeIsBalanced(tree->left) && BinaryTreeIsBalanced(tree->right);
// }

// Make return UNBALANCED_TREE if either tree->left or tree->left is unbalanced

int BinaryTreeHeight(BinaryTree *tree) {

    if (tree == NULL)
        return 0;

    int heightLeft = BinaryTreeHeight(tree->left);
    if (heightLeft == UNBALANCED_TREE) {
        return UNBALANCED_TREE;
    }

    int heightRight = BinaryTreeHeight(tree->right);
    if (heightRight == UNBALANCED_TREE) {
        return UNBALANCED_TREE;
    }

    if (abs(heightLeft - heightRight) > BALANCE_HEIGHT_DIFFERENCE_MAX) {
        return UNBALANCED_TREE;
    }

    return 1 + MAX(heightLeft, heightRight);
}

bool BinaryTreeIsBalanced(BinaryTree *tree) {

    if (tree == NULL) {
        return true;
    }

    return BinaryTreeHeight(tree) != UNBALANCED_TREE;
}
