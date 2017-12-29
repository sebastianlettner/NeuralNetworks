//
// Created by Sebastian Lettner on 10.12.17.
//

#ifndef NEURALNETWORK_COPYMATRIX_H
#define NEURALNETWORK_COPYMATRIX_H

#include "../Matrix.h"

struct Matrix* copy_matrix(struct Matrix* A) {

    struct Matrix* copy = create_matrix(A->dim1,A->dim2);
    copy->dim1 = A->dim1;
    copy->dim2 = A->dim2;

    for (int i = 0; i < copy->dim1; ++i) {
        for (int j = 0; j < copy->dim2; ++j) {
            copy->matrix[i][j] = A->matrix[i][j];
        }
    }
    return copy;
}

#endif //NEURALNETWORK_COPYMATRIX_H
