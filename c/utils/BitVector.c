#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <BitVector.h>

BitVector *BitVectorNew(size_t numSlots) {

    BitVector *v = malloc(sizeof(BitVector));
    v->numSlots = numSlots;
    v->slots = malloc(sizeof(char) * ceil((float) numSlots / sizeof(char)));

    return v;
}

void BitVectorSet(BitVector *v, int slot) {

    int binNum = floor((float) slot / 8);
    int slotInBin = slot % 8;
    v->slots[binNum] |= 1 << slotInBin;
}

bool BitVectorGet(BitVector *v, int slot) {

    int binNum = floor((float) slot / 8);
    int slotInBin = slot % 8;
    return (v->slots[binNum] & 1 << slotInBin) > 0;
}