#include <stdio.h>
#include <math.h>

#define N 5

void rotate90(int matrix[N][N]) {

    for (int layer = 0; layer < floor(N/2); layer++) {
        for (int offset = layer; offset < N - 1 - layer; offset++) {
            // save the top to temp variable
            int temp = matrix[offset][layer];
            // copy left => top
            matrix[offset][layer] = matrix[layer][N - 1 - offset];
            // copy bottom => left
            matrix[layer][N - 1 - offset] = matrix[N - 1 - offset][N - 1 - layer];
            // copy right => bottom
            matrix[N - 1 - offset][N - 1 - layer] = matrix[N - 1 - layer][offset];
            // put top in right
            matrix[N - 1 - layer][offset] = temp;
        }
    }
}

void printMatrix(int matrix[N][N]) {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("| %2d ", matrix[j][i]);
        }
        printf("|\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {

    int matrix[N][N] = {
        {1,6,11,16,21},
        {2,7,12,17,22},
        {3,8,13,18,23},
        {4,9,14,19,24},
        {5,10,15,20,25}
    };

    // Do a 360

    printMatrix(matrix);
    rotate90(matrix);
    printMatrix(matrix);
    rotate90(matrix);
    printMatrix(matrix);
    rotate90(matrix);
    printMatrix(matrix);
    rotate90(matrix);
    printMatrix(matrix);
    return 0;
}
