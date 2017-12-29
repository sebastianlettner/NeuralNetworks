//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_RECTIFIEDLINEARUNIT_H
#define NEURALNETWORK_RECTIFIEDLINEARUNIT_H

#include "../Helpers/Matrix.h"
#include <math.h>
#include "../Helpers/Vector.h"
#include "../Helpers/MatrixOperations/MatrixElementOperation.h"

double relu_function(double val) {

    if (val>=0) {
        return val;
    }
    else {
        return  0;
    }

}

double relu_gradient(double val) {

    if (val>=0) {
        return 1;
    }
    else {
        return  0;
    }

}

struct Matrix* relu_mat(struct Matrix* A) {


    struct Matrix* B = create_matrix(A->dim1, A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = relu_function(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* relu_vec(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = relu_function(b->vec[i]);
    }
    return vec;

}

struct Matrix* relu_mat_grad(struct Matrix* A) {

    struct Matrix* B = create_matrix(A->dim1, A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = relu_gradient(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* relu_vec_grad(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = relu_gradient(b->vec[i]);
    }
    return vec;

}

struct Matrix* relu_backward(struct Matrix* dA, struct Matrix* Z) {

    struct Matrix* Z_grad = relu_mat_grad(Z);
    struct Matrix* res = matrix_matrix_operation(dA,Z_grad,multiply);
    free_mat(Z_grad);
    return res;

}

#endif //NEURALNETWORK_RECTIFIEDLINEARUNIT_H
