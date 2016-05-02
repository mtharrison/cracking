#include <math.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedListNode *AddLists(LinkedListNode *l1, LinkedListNode *l2) {

    int result;
    int carry = 0;
    LinkedListNode *returnList = NULL;
    LinkedListNode *returnListCurrPtr = NULL;

    // If we've not reached the end of both lists keep iterating through

    while (l1 != NULL && l2 != NULL) {

        // Take the val or 0 if current pointer is NULL

        int lhs = l1 == NULL ? 0 : l1->val;
        int rhs = l2 == NULL ? 0 : l2->val;

        result = lhs + rhs + carry;

        if (result > 9) {
            carry = 1;
            result = result % 10;
        }
        else {
            carry = 0;
        }

        LinkedListNode *node = LinkedListNew(result, NULL);

        if (returnList == NULL) {
            returnList = node;
            returnListCurrPtr = node;
        }
        else {
            returnListCurrPtr->next = node;
            returnListCurrPtr = node;
        }

        // Advance our lists

        l1 = l1 == NULL ? NULL : l1->next;
        l2 = l2 == NULL ? NULL : l2->next;
    }

    // Take care of a final carry

    if (carry) {
        LinkedListNode *node = LinkedListNew(carry, NULL);
        returnListCurrPtr->next = node;
    }

    return returnList;
}

int main(int argc, char **argv) {

    LinkedListNode C1 = { 6, NULL };
    LinkedListNode B1 = { 1, &C1 };
    LinkedListNode A1 = { 7, &B1 };

    LinkedListPrint(&A1);

    LinkedListNode C2 = { 2, NULL };
    LinkedListNode B2 = { 9, &C2 };
    LinkedListNode A2 = { 5, &B2 };

    printf("\t+\n");

    LinkedListPrint(&A2);

    printf("\t=\n");

    LinkedListNode *result = AddLists(&A1, &A2);

    LinkedListPrint(result);

    return 0;
}
