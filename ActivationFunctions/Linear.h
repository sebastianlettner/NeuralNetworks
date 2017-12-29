//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_LINEAR_H
#define NEURALNETWORK_LINEAR_H

#include "../Helpers/Matrix.h"
#include <math.h>
#include "../Helpers/Vector.h"
#include "../Helpers/MatrixOperations/MatrixMatrixMultiplikation.h"
#include "../Helpers/MatrixOperations/MatrixElementOperation.h"

double linear_function(double val) {

    return val;

}



struct Matrix* linear_mat(struct Matrix* A) {

    struct Matrix* B = create_matrix(A->dim1, A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = linear_function(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* linear_vec(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = linear_function(b->vec[i]);
    }
    return vec;

}

struct Matrix* linear_mat_grad(struct Matrix* A) {

    struct Matrix* B = create_matrix(A->dim1, A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = 1;
        }
    }
    return B;

}

struct Vector* linear_vec_grad(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = 1;
    }
    return vec;

}

struct Matrix* linear_backwards(struct Matrix* dA, struct Matrix* Z) {

    struct Matrix* Z_grad = linear_mat_grad(Z);
    struct Matrix* res =  matrix_matrix_operation(dA,Z_grad,multiply);
    free_mat(Z_grad);
    return res;

}

#endif //NEURALNETWORK_LINEAR_H
