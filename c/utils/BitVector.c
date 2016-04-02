#include "BitVector.h"

BitVector *BitVectorNew(size_t numSlots) {

    BitVector *v = malloc(sizeof(BitVector));
    v->numSlots = numSlots;

    size_t bytes = sizeof(char) * ceil((float) numSlots / sizeof(char));

    v->slots = malloc(bytes);
    memset(v->slots, 0, bytes);

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
