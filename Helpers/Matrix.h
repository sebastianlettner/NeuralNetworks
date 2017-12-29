//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_MATRIX_H
#define NEURALNETWORK_MATRIX_H

#include <stdio.h>
#include "stdlib.h"
#include "ranlib.h"


double double_rand_mat(double min, double max) {


    double scale = (double)rand() / (double) RAND_MAX;
    return min + scale * (max-min);

}




struct Matrix {

    int dim1;
    int dim2;
    double** matrix;

};

struct Matrix* create_matrix(int dim1, int dim2) {

    struct Matrix* mat = (struct Matrix*)malloc(sizeof(struct Matrix));
    //printf("malloc in Zeile %d der Datei %s (%ld Bytes) \n" ,__LINE__,__FILE__, sizeof(struct Matrix));

    mat->matrix = (double **) malloc(sizeof(double *) * dim1);
    //printf("malloc in Zeile %d der Datei %s (%ld Bytes) \n" ,__LINE__,__FILE__, sizeof(double *) * dim1);
    int i = 0;
    for (i = 0; i < dim1; i++) {
        /* Allocate array, store pointer  */
        mat->matrix[i] = (double *) malloc(sizeof(double) * dim2);
        //printf("malloc in Zeile %d der Datei %s (%ld Bytes) \n" ,__LINE__,__FILE__, sizeof(double) * dim2);
    }
    mat->dim1 = dim1;
    mat->dim2 = dim2;
    return mat;
}

struct Matrix* mat_ones(int dim1, int dim2) {

    struct Matrix* A = create_matrix(dim1,dim2);
    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            A->matrix[i][j] = 1;
        }
    }
    return A;
}

struct Matrix* mat_zeros(int dim1, int dim2) {

    struct Matrix* A = create_matrix(dim1,dim2);
    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            A->matrix[i][j] = 0;
        }
    }
    return A;
}

struct Matrix* mat_rand(int dim1, int dim2) {

    struct Matrix* A = create_matrix(dim1,dim2);
    for (int i = 0; i < A->dim1; ++i) {
        for (int j = 0; j < A->dim2; ++j) {
            A->matrix[i][j] = double_rand_mat(-10,10);
        }
    }
    return A;
}

void free_mat(struct Matrix* mat) {

    for (int k = 0; k < mat->dim1; ++k) {
        free(mat->matrix[k]);
        //printf("free in Zeile %d der Datei %s (%ld Bytes) \n" ,__LINE__,__FILE__, sizeof(mat->matrix[k]));

    }
    free(mat->matrix);
    //printf("free in Zeile %d der Datei %s (%ld Bytes) \n" ,__LINE__,__FILE__, sizeof(mat->matrix));
    free(mat);
    //printf("free in Zeile %d der Datei %s (%ld Bytes) \n" ,__LINE__,__FILE__, sizeof(mat));
}

#endif //NEURALNETWORK_MATRIX_H
