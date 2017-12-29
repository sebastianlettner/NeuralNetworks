//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_TANGENSHYPERBOLIKUS_H
#define NEURALNETWORK_TANGENSHYPERBOLIKUS_H

#include "../Helpers/Matrix.h"
#include "../Helpers/Vector.h"
#include <math.h>
#include "../Helpers/MatrixOperations/MatrixElementOperation.h"

double tanh_function(double value) {


    return tanh(value);

}

double tanh_gradient(double value) {

    return (1 - pow(tanh(value),2));

}

struct Matrix* tanh_mat(struct Matrix* A) {


    struct Matrix* B = create_matrix(A->dim1, A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = tanh_function(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* tanh_vec(struct Vector* b) {

    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = tanh_function(b->vec[i]);
    }
    return vec;

}

struct Matrix* tanh_mat_grad(struct Matrix* A) {

    struct Matrix* B = create_matrix(A->dim1, A->dim2);
    for (int i = 0; i < A->dim1 ; ++i) {
        for (int j = 0; j < A->dim2 ; ++j) {
            B->matrix[i][j] = tanh_gradient(A->matrix[i][j]);
        }
    }
    return B;

}

struct Vector* tanh_vec_grad(struct Vector* b) {


    struct Vector* vec = create_Vector(b->dim);
    for (int i = 0; i < b->dim; ++i) {
        vec->vec[i] = tanh_gradient(b->vec[i]);
    }
    return vec;

}

struct Matrix* tanh_backward(struct Matrix* dA, struct Matrix* Z) {

    struct Matrix* Z_grad = tanh_mat_grad(Z);
    struct Matrix* res =  matrix_matrix_operation(dA,Z_grad,multiply);
    free_mat(Z_grad);
    return res;
}

#endif //NEURALNETWORK_TANGENSHYPERBOLIKUS_H
