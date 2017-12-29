//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_VECTOR_H
#define NEURALNETWORK_VECTOR_H

#include <stdlib.h>

typedef struct Vector {

    double* vec;
    int dim;

} Vector;

struct Vector* create_Vector(int dim) {

    struct Vector* vector = (struct Vector*)malloc(sizeof(struct Vector));

    vector->vec = (double*)malloc(sizeof(double)*dim);
    vector->dim = dim;
    return vector;
}

struct Vector* vec_ones(int dim) {
    struct Vector* vec = create_Vector(dim);
    for (int i = 0; i < vec->dim; ++i) {
        vec->vec[i] = 1;
    }
    return vec;
}

struct Vector* vec_zeros(int dim) {
    struct Vector* vec = create_Vector(dim);
    for (int i = 0; i < vec->dim; ++i) {
        vec->vec[i] = 0;
    }
    return vec;
}

void free_vec(struct Vector* vec) {
    free(vec->vec);
    free(vec);
}
#endif //NEURALNETWORK_VECTOR_H
