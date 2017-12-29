//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_SUM_H
#define NEURALNETWORKLIB_SUM_H

#include "Matrix.h"
#include "Vector.h"


struct Vector* sum_mat(struct Matrix* A, int axis) {



    if (axis == 0) {

        struct Vector* vec = create_Vector(A->dim1);
        //Sum all columns togehter -> A 3x4 Matrix turns into a 3x1 Vector
        for (int i = 0; i < A->dim1; i++) {
            double sum = 0;
            for (int j = 0; j < A->dim2; ++j) {
                sum += A->matrix[i][j];
            }
            vec->vec[i] = sum;
        }
        return vec;
    }

    else {

        struct Vector *vec = create_Vector(A->dim2);
        //Sum all rows togehter -> A 3x4 Matrix turns into a 1x4 Vector
        for (int i = 0; i < A->dim2; i++) {
            double sum = 0;
            for (int j = 0; j < A->dim1; ++j) {
                sum += A->matrix[j][i];
            }
            vec->vec[i] = sum;
        }
        return vec;
    }
}

double sum_vec(struct Vector* vec) {

    double sum = 0;
    for (int i = 0; i < vec->dim; ++i) {
        sum += vec->vec[i];
    }
    return sum;
}

#endif //NEURALNETWORKLIB_SUM_H
