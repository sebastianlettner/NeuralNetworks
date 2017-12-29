//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_PRINTVEC_H
#define NEURALNETWORKLIB_PRINTVEC_H

#include "../Vector.h"
#include <stdio.h>

void print_vec(struct Vector* a) {

    for (int i = 0; i < a->dim; ++i) {
            printf("%f\n", a->vec[i]);
        }

}

void print_vec_dims(struct Vector* a) {

    printf("%d \n", a->dim);
    printf("\n");
    printf("\n");


}


#endif //NEURALNETWORKLIB_PRINTVEC_H
