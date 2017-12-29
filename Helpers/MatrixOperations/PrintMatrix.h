//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_PRINTMATRIX_H
#define NEURALNETWORKLIB_PRINTMATRIX_H

#include "../Matrix.h"
#include <stdio.h>

void print_mat(struct Matrix* A) {

    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            printf("%.7f ", A->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");


}

void print_mat_dims(struct Matrix* A) {

    printf("%dx%d \n", A->dim1,A->dim2);
    printf("\n");
    printf("\n");


}

#endif //NEURALNETWORKLIB_PRINTMATRIX_H
