//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_LINEARBACKWARD_H
#define NEURALNETWORKLIB_LINEARBACKWARD_H

#include "../Helpers/MatrixOperations/Transpose.h"
#include "../Helpers/MatrixOperations/MatrixElementOperation.h"
#include "../Helpers/VectorOperations/VectorElementOperation.h"
#include "../Helpers/Sum.h"
#include "../Helpers/MatrixOperations/MatrixMatrixMultiplikation.h"
#include "../ActivationFunctions/RectifiedLinearUnit.h"
#include "../ActivationFunctions/Sigmoid.h"
#include "../ActivationFunctions/Linear.h"
#include "../ActivationFunctions/TangensHyperbolikus.h"
#include "../Caches/Cache.h"
#include "../Caches/Caches.h"
#include "../Parameters/InitializeParameters.h"


typedef struct Derivative_Cache {

    struct Matrix* dA_prev;
    struct Matrix* dW;
    struct Vector* db;

} Derivative_Cache;

struct Derivative_Cache* create_derivative_cache( struct Matrix* dA_prev, struct Matrix* dW, struct Vector* db ) {

    struct Derivative_Cache* d_cache = (struct Derivative_Cache*)malloc(sizeof(struct Derivative_Cache));
    d_cache->dA_prev = dA_prev;
    d_cache->db = db;
    d_cache->dW = dW;
    return d_cache;

}

struct Derivative_Cache* linear_backward(struct Matrix* dZ, struct Cache* cache) {

    /*
     * Implement the linear portion of backward propagation for a single layer
     */
    struct Matrix* A_prev = cache->A_prev;
    struct Matrix* W = cache->W;
    //struct Vector* b =cache->b;

    double m = A_prev->dim2;
    double factor  = (double)1/m;

    struct Matrix* A_prev_t = mat_transpose(A_prev);
    struct Matrix* dW_temp = matrix_matrix_multiplikation(dZ, A_prev_t);
    struct Matrix* dW = matrix_element_number_operation(dW_temp,factor,multiply);

    struct Vector* db = vector_element_number_operation(sum_mat(dZ,0),factor,multiply);
    struct Matrix* W_t = mat_transpose(W);
    struct Matrix* dA_prev = matrix_matrix_multiplikation(W_t,dZ);

    free_mat(dZ);
    free_mat(dW_temp);
    free_mat(A_prev_t);
    free_mat(W_t);


    return create_derivative_cache(dA_prev,dW,db);

}


#endif //NEURALNETWORKLIB_LINEARBACKWARD_H
