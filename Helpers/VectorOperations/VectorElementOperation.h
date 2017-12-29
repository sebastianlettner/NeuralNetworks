//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_VECTORELEMENTOPERATION_H
#define NEURALNETWORKLIB_VECTORELEMENTOPERATION_H

#include "../Vector.h"
#include "../Operations/operations.h"
#include <stdio.h>

struct Vector* vector_operation(struct Vector* a, double (*operation) (double)) {

    for (int i = 0; i < a->dim; ++i) {
       a->vec[i] = operation(a->vec[i]);
    }
    return a;

}

struct Vector* vector_element_number_operation(struct Vector* a, double number,  double (*operation) (double,double)) {

    struct Vector* res = create_Vector(a->dim);
    for (int i = 0; i < a->dim; ++i) {
            res->vec[i] = operation(a->vec[i], number);
    }
    return res;

}

struct Vector* vector_vector_operation(struct Vector* a, struct Vector* b, double (*operation) (double,double)) {


    struct Vector* res = create_Vector(a->dim);
    if ((a->dim != b->dim)) {
        printf("DIMENSION MISMATCH\n");
    }

    for (int i = 0; i < a->dim; ++i) {
           res->vec[i] = operation(a->vec[i],b->vec[i]);
        }
    return res;

}


#endif //NEURALNETWORKLIB_VECTORELEMENTOPERATION_H
