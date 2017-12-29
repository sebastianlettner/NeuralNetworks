//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_MATRIXVECTORBROADCASTADDTION_H
#define NEURALNETWORK_MATRIXVECTORBROADCASTADDTION_H


#include "../../Helpers/Matrix.h"
#include "../../Helpers/Vector.h"

struct Matrix* matrix_vector_broadcast_addition(struct Matrix* A, struct Vector* b, double (*operation) (double,double)) {

    /*
     * We can either add b to every coloum od A or to every row
     * Else error!
     */

    if (A->dim1 == b->dim) {
        for (int i = 0; i < A->dim1; ++i) {
            for (int j = 0; j < A->dim2 ; ++j) {
                A->matrix[i][j] = operation(A->matrix[i][j],b->vec[i]);
            }

        }
    }

    else if (A->dim2 == b->dim) {
        for (int i = 0; i <A->dim2 ; ++i) {
            for (int j = 0; j <A->dim1 ; ++j) {
                A->matrix[j][i] = operation(A->matrix[j][i],b->vec[i]);
            }
        }
    }
    else {
        printf("DIMENSION MISMATCH!(MatrixVectorAddition)\n");
    }

    return A;

}

#endif //NEURALNETWORK_MATRIXVECTORBROADCASTADDTION_H
