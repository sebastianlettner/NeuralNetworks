//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_VECTORVECTORADDITION_H
#define NEURALNETWORK_VECTORVECTORADDITION_H

#include "../Vector.h"
#include "stdio.h"

struct Vector* vector_vector_addtion(struct Vector* a,struct Vector* b) {

    if (a->dim != b->dim) {
        printf("VECTOR DIMENSIONS MUST AGREE!\n");
        return a;
    }

    for (int i = 0; i < a->dim; ++i) {
        a->vec[i] = a->vec[i] + b->vec[i];
    }
    return a;
}

#endif //NEURALNETWORK_VECTORVECTORADDITION_H
