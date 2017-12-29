//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_SIGMOID_H
#define NEURALNETWORK_SIGMOID_H

#include "../Helpers/Matrix.h"
#include "../Helpers/Vector.h"
#include <math.h>
#include "../Helpers/MatrixOperations/MatrixElementOperation.h"
#include "../Helpers/MatrixOperations/PrintMatrix.h"
#include "../Helpers/MatrixOperations/CopyMatrix.h"



double sigmoid_function(double value) {

    double temp = 1 + exp(-value);
    temp = 1/temp;
    return temp;

}

double sigmoid_gradient(double value) {

    return (sigmoid_function(value)*(1 - sigmoid_function(value)));

}

struct Matrix* sigmoid_mat(struct Matrix* A) {

    struct Matrix* B = create_matrix(A->dim1,A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = sigmoid_function(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* sigmoid_vec(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = sigmoid_function(b->vec[i]);
    }
    return vec;

}

struct Matrix* sigmoid_mat_grad(struct Matrix* A) {

    struct Matrix* B = create_matrix(A->dim1,A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = sigmoid_gradient(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* sigmoid_vec_grad(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = sigmoid_gradient(b->vec[i]);
    }
    return vec;

}

struct Matrix* sigmoid_backward(struct Matrix* dA, struct Matrix* Z) {


    struct Matrix* Z_grad = sigmoid_mat_grad(Z);
    struct Matrix* res = matrix_matrix_operation(dA,Z_grad,multiply);
    free_mat(Z_grad);
    return res;

}

#endif //NEURALNETWORK_SIGMOID_H
