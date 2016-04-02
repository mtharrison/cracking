#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct BitVector {
    size_t numSlots;
    char *slots;
};

typedef struct BitVector BitVector;

BitVector *BitVectorNew(size_t numSlots);
void BitVectorSet(BitVector *v, int slot);
bool BitVectorGet(BitVector *v, int slot);
