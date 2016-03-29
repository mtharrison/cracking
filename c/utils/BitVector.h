#include <stdbool.h>

struct BitVector {
    size_t numSlots;
    char *slots;
};

typedef struct BitVector BitVector;

BitVector *BitVectorNew(size_t numSlots);
void BitVectorSet(BitVector *v, int slot);
bool BitVectorGet(BitVector *v, int slot);
