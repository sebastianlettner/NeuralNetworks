//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_LINEARFORWARD_H
#define NEURALNETWORK_LINEARFORWARD_H


#include "../Caches/Cache.h"
#include "../Helpers/MatrixOperations/MatrixMatrixMultiplikation.h"
#include "../Helpers/VectorOperations/VectorVectorAddition.h"
#include "../Helpers/MatrixOperations/MatrixVectorBroadcastAddtion.h"
#include "../Helpers/Operations/operations.h"
#include "../Helpers/MatrixOperations/PrintMatrix.h"
#include "../Helpers/VectorOperations/PrintVec.h"

struct Cache* linear_forward(struct Matrix* A_prev,struct Matrix* W,struct Vector* b) {



    if (A_prev->dim1 != W->dim2) {
        printf("DIMENSION MISMATCH IN LINEAR FORWARD1!\n");
    }

    struct Matrix* Z = matrix_matrix_multiplikation(W,A_prev);
    //Adding b to every column of Z
    if (Z->dim1 != b->dim) {
        printf("DIMENSION MISMATCH IN LINEAR FORWARD2!\n");
    }
    Z = matrix_vector_broadcast_addition(Z,b,add);
    return create_cache(A_prev, W, b, Z);


}



#endif //NEURALNETWORK_LINEARFORWARD_H
