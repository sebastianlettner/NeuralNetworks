//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_MATRIXMATRIXMULTIPLIKATION_H
#define NEURALNETWORK_MATRIXMATRIXMULTIPLIKATION_H


#include "../Matrix.h"
#include "stdio.h"

struct Matrix* matrix_matrix_multiplikation(struct Matrix* A, struct Matrix* B) {

    if (A->dim2 != B->dim1) {
        printf("MATRIX DIMENSIONS MUST AGREE!\n");
        return A;
    }

    struct Matrix* C = create_matrix(A->dim1,B->dim2);
    double sum = 0;
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < B->dim2; ++j) {
            for (int k = 0; k <B->dim1 ; ++k) {
                sum += A->matrix[i][k]*B->matrix[k][j];
            }
            C->matrix[i][j] = sum;
            sum = 0;
        }
    }
    return C;

}

#endif //NEURALNETWORK_MATRIXMATRIXMULTIPLIKATION_H
