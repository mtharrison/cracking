#include <stdio.h>
#include <math.h>
#include "BitVector.h"

#define N 3
#define M 5

void zeroRowAndCol(int matrix[N][M]) {

    BitVector *row_bv = BitVectorNew(M);
    BitVector *col_bv = BitVectorNew(N);

    // Go through once and mark cols and rows to zero out

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int el = matrix[j][i];
            if (el == 0) {
                BitVectorSet(row_bv, i);
                BitVectorSet(col_bv, j);
            }
        }
    }

    // Go through again and zero out and columns affected

    for(int i = 0; i < M; i++) {
        bool row_clear = BitVectorGet(row_bv, i);
        for(int j = 0; j < N; j++) {
            bool col_clear = BitVectorGet(col_bv, j);
            if (row_clear || col_clear) {
                matrix[j][i] = 0;
            }
        }
    }

    free(row_bv);
    free(col_bv);
}

void printMatrix(int matrix[N][M]) {

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("| %2d ", matrix[j][i]);
        }
        printf("|\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {

    int matrix[N][M] = {
        {1,4,7,10,13},
        {2,5,0,11,14},
        {3,6,9,12,15}
    };

    printMatrix(matrix);
    zeroRowAndCol(matrix);
    printMatrix(matrix);

    int matrix2[N][M] = {
        {1,4,7,10,13},
        {2,5,8,11,14},
        {3,6,9,12,0}
    };

    printMatrix(matrix2);
    zeroRowAndCol(matrix2);
    printMatrix(matrix2);
    return 0;
}
