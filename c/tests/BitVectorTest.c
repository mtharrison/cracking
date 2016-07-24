#include <assert.h>
#include "BitVector.h"

int main(int argc, char const **argv) {

	BitVector *bv = BitVectorNew(5);
	assert(BitVectorGet(bv, 0) == 0);
	assert(BitVectorGet(bv, 1) == 0);
	assert(BitVectorGet(bv, 2) == 0);
	assert(BitVectorGet(bv, 3) == 0);
	assert(BitVectorGet(bv, 4) == 0);

	BitVectorSet(bv, 3);
	BitVectorSet(bv, 4);
	assert(BitVectorGet(bv, 0) == 0);
	assert(BitVectorGet(bv, 1) == 0);
	assert(BitVectorGet(bv, 2) == 0);
	assert(BitVectorGet(bv, 3) == 1);
	assert(BitVectorGet(bv, 4) == 1);

	BitVectorClear(bv, 3);
	assert(BitVectorGet(bv, 0) == 0);
	assert(BitVectorGet(bv, 1) == 0);
	assert(BitVectorGet(bv, 2) == 0);
	assert(BitVectorGet(bv, 3) == 0);
	assert(BitVectorGet(bv, 4) == 1);

	BitVectorDestroy(&bv);
	assert(bv == NULL);

	return 0;
}
