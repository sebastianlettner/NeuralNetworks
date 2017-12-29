//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_MATRIXELEMENTOPERATION_H
#define NEURALNETWORKLIB_MATRIXELEMENTOPERATION_H

#include "../Matrix.h"
#include "../Operations/operations.h"

struct Matrix* matrix_operation(struct Matrix* A, double (*operation) (double)) {

    struct Matrix* C = create_matrix(A->dim1,A->dim2);

    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            C->matrix[i][j] = operation(A->matrix[i][j]);
        }
    }
    return C;

}

struct Matrix* matrix_element_number_operation(struct Matrix* A, double number,  double (*operation) (double,double)) {

    struct Matrix* C = create_matrix(A->dim1,A->dim2);

    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            C->matrix[i][j] = operation(A->matrix[i][j], number);
        }
    }
    return C;

}

struct Matrix* matrix_matrix_operation(struct Matrix* A, struct Matrix* B, double (*operation) (double,double)) {

    struct Matrix* C = create_matrix(A->dim1,B->dim2);

    if ((A->dim1 != B->dim1) || (A->dim2 != B->dim2)) {
        printf("DIMENSION MISMATCH\n");
    }

    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            C->matrix[i][j] = operation(A->matrix[i][j],B->matrix[i][j]);
        }
    }
    return C;

}

#endif //NEURALNETWORKLIB_MATRIXELEMENTOPERATION_H
