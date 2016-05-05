#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "LinkedList.h"


// This algorithm is simple:
// 1. Reverse the list
// 2. Compare the original and reversed list element-wise
//
// Complexity: time O(n), space O(n)

bool IsPallindromeSimple(LinkedListNode *list) {

    LinkedListNode *orig = list;
    LinkedListNode *rev;
    LinkedListNode *next = NULL;

    int i = 0;

    while (list) {
        rev = LinkedListNew(list->val, next);
        next = rev;
        list = list->next;
        i++;
    }

    if (i < 3) {
        return true;    // 2 or less items and it must be a pallindrome
    }

    list = orig;

    // Could optimize here by just comparing first half

    while (list) {
        if (list->val != rev->val) {
            return false;
        }
        list = list->next;
        rev = rev->next;
    }

    return true;
}


// This algorithm requires a constant growth space and linear time
// It exploits the fundamental theorem of arithmetic to compute numbers from
// prime factors to compare the split list of integers. This avoids creating
// a new list but expects only integer values
//
// Complexity: time O(n), space O(1)

bool IsPallindromeAlt(LinkedListNode *list) {

    int primes[] = {2,3,5,7};
    LinkedListNode *orig = list;

    // Find N

    int N = 0;

    while (list) {
        N++;
        list = list->next;
    }

    int startPoint = ceil((float) N / 2);

    LinkedListNode *ptr1 = orig;
    LinkedListNode *ptr2 = orig;

    N = 0;

    while (N < startPoint) {
        N++;
        ptr2 = ptr2->next;
    }

    int a = 1;
    int b = 1;

    while (ptr2) {
        a *= primes[ptr1->val - 1];
        b *= primes[ptr2->val - 1];

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return a == b;
}


int main(int argc, char **argv) {

    int valuesA [] = {1,2,3,4,4,3,2,1};
    LinkedListNode *A = LinkedListQuickCreate(valuesA, 8);

    assert(IsPallindromeSimple(A) == true);
    assert(IsPallindromeAlt(A) == true);

    int valuesB [] = {1,2,3,4,3,2,1};
    LinkedListNode *B = LinkedListQuickCreate(valuesB, 7);

    assert(IsPallindromeSimple(B) == true);
    assert(IsPallindromeAlt(B) == true);

    int valuesC [] = {1,2,3,4,3,1};
    LinkedListNode *C = LinkedListQuickCreate(valuesC, 6);

    assert(IsPallindromeSimple(C) == false);
    assert(IsPallindromeAlt(C) == false);

    return 0;
}
