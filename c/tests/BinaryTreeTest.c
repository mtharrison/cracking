#include <assert.h>
#include <stdbool.h>
#include "BinaryTree.h"

void test1() {
    BinaryTree *basicTree = BinaryTreeNodeCreate(42, NULL, NULL);
    assert(basicTree->val == 42);
    assert(basicTree->left == NULL);
    assert(basicTree->right == NULL);
    assert(BinaryTreeHeight(basicTree) == 1);
}

void test2() {
    /*
             1
            / \
           2   3
          /\   /\
         4  5 6  7
    */
    // Build 3rd level

    BinaryTree *node4 = BinaryTreeNodeCreate(4, NULL, NULL);
    BinaryTree *node5 = BinaryTreeNodeCreate(5, NULL, NULL);
    BinaryTree *node6 = BinaryTreeNodeCreate(6, NULL, NULL);
    BinaryTree *node7 = BinaryTreeNodeCreate(7, NULL, NULL);

    // Build 2nd level

    BinaryTree *node2 = BinaryTreeNodeCreate(2, node4, node5);
    BinaryTree *node3 = BinaryTreeNodeCreate(3, node6, node7);

    // Build 1st level

    BinaryTree *tree = BinaryTreeNodeCreate(1, node2, node3);

    // Confirm the heights of all subtrees

    assert(BinaryTreeHeight(tree) == 3);
    assert(BinaryTreeHeight(tree->left) == 2);
    assert(BinaryTreeHeight(tree->right) == 2);
    assert(BinaryTreeHeight(tree->left->left) == 1);
    assert(BinaryTreeHeight(tree->right->right) == 1);

    assert(BinaryTreeIsBalanced(tree) == true);
}

void test3() {
    /*
             1
            / \
           2   3
          /\
         4  5
    */
    // Build 3rd level

    BinaryTree *node4 = BinaryTreeNodeCreate(4, NULL, NULL);
    BinaryTree *node5 = BinaryTreeNodeCreate(5, NULL, NULL);

    // Build 2nd level

    BinaryTree *node2 = BinaryTreeNodeCreate(2, node4, node5);
    BinaryTree *node3 = BinaryTreeNodeCreate(3, NULL, NULL);

    // Build 1st level

    BinaryTree *tree = BinaryTreeNodeCreate(1, node2, node3);

    // Confirm the heights of all subtrees

    assert(BinaryTreeHeight(tree) == 3);
    assert(BinaryTreeHeight(tree->left) == 2);
    assert(BinaryTreeHeight(tree->right) == 1);
    assert(BinaryTreeHeight(tree->left->left) == 1);
    assert(BinaryTreeHeight(tree->left->right) == 1);

    assert(BinaryTreeIsBalanced(tree) == true);
}

void test4() {
    /*
             1
            /
           2
          /\
         4  5
    */
    // Build 3rd level

    BinaryTree *node4 = BinaryTreeNodeCreate(4, NULL, NULL);
    BinaryTree *node5 = BinaryTreeNodeCreate(5, NULL, NULL);

    // Build 2nd level

    BinaryTree *node2 = BinaryTreeNodeCreate(2, node4, node5);

    // Build 1st level

    BinaryTree *tree = BinaryTreeNodeCreate(1, node2, NULL);

    // Confirm the heights of all subtrees

    assert(BinaryTreeHeight(tree) == 3);
    assert(BinaryTreeHeight(tree->left) == 2);
    assert(BinaryTreeHeight(tree->left->left) == 1);
    assert(BinaryTreeHeight(tree->left->right) == 1);

    assert(BinaryTreeIsBalanced(tree) == false);
}


int main(int argc, char const **argv) {

    test1();
    test2();
    test3();
    test4();

    return 0;
}
