#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BitVector_T {
    size_t numSlots;
    char *slots;
} BitVector;

BitVector *BitVectorNew(const size_t numSlots);
void BitVectorSet(BitVector *v, const int slot);
void BitVectorClear(BitVector *v, const int slot);
bool BitVectorGet(BitVector *v, const int slot);
void BitVectorDestroy(BitVector **bvPtr);
