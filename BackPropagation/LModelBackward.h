//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_LMODELBACKWARDCLASSIFICATION_H
#define NEURALNETWORKLIB_LMODELBACKWARDCLASSIFICATION_H

#include "LinearActivationBackward.h"
#include "../Helpers/MatrixOperations/PrintMatrix.h"
#include "../Helpers/VectorOperations/PrintVec.h"

typedef struct GradientsContainer {

    int num_grads;
    struct Derivative_Cache** grads;

} GradientsContainer;

struct GradientsContainer* create_GradientsContainer(int num_grads) {

    struct GradientsContainer* grad_cont = (struct GradientsContainer*)malloc(sizeof(struct GradientsContainer*));
    grad_cont->grads = (struct Derivative_Cache**)malloc(sizeof(struct Derivative_Cache*)*num_grads);
    for (int i = 0; i < num_grads ; ++i) {
        grad_cont->grads[i] = (struct Derivative_Cache*)malloc(sizeof(struct Derivative_Cache));
    }
    grad_cont->num_grads = num_grads;
    return grad_cont;
};


struct GradientsContainer* L_model_backward_classification(struct Matrix* AL, struct Matrix* Y, struct Caches* caches) {


    /*
    * Implement the backward propagation for the [LINEAR->RELU] * (L-1) -> LINEAR -> sigmoid group
    *   AL -- probability vector, output of the forward propagation (L_model_forward())
    *   Y -- true "label" vector (containing 0 if non-cat, 1 if cat)
    *    caches -- list of caches containing:
    *          every cache of linear_activation_forward() with "relu" (it's caches[l], for l in range(L-1) i.e l = 0...L-2)
    *           the cache of linear_activation_forward() with "sigmoid" (it's caches[L-1])
    *
    *   Returns:
    *       grads -- A dictionary with the "gradients"
    *
    *
    */
    struct GradientsContainer* grads = create_GradientsContainer(caches->num_caches);
    int L = caches->num_caches; //Number of layers - 1 e.g number parameters
    double m = AL->dim2;
    //initialize the backpropagation

    struct Matrix* dAL = matrix_matrix_operation(Y,AL,divide); // Y/AL
    struct Matrix* dAL2 = matrix_matrix_operation(mat_ones(Y->dim1,Y->dim2),Y,subtract); //1-Y
    struct Matrix* dAL3 = matrix_matrix_operation(mat_ones(AL->dim1,AL->dim2),AL,subtract); //1-AL
    dAL2 = matrix_matrix_operation(dAL2,dAL3,divide); // (1-Y)/(1-AL)
    dAL = matrix_matrix_operation(dAL,dAL2,subtract); // Y/AL - (1-Y)/(1-AL)
    dAL = matrix_element_number_operation(dAL, -1.0, multiply); // - Y/AL + (1-Y)/(1-AL)

    //Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "AL, Y, caches". Outputs: "grads["dAL"], grads["dWL"], grads["dbL"]
    struct Derivative_Cache* currentcache = linear_activation_backward(dAL, caches->cache[L-1], 's');
    grads->grads[L-1] = currentcache;



    for (int i = L-2; i >= 0 ; --i) {

        currentcache = linear_activation_backward(grads->grads[i+1]->dA_prev,caches->cache[i], 't');
        grads->grads[i]->dA_prev = currentcache->dA_prev;
        grads->grads[i]->dW = currentcache->dW;
        grads->grads[i]->db = currentcache->db;

    }



    return grads;
}

struct GradientsContainer* L_model_backward_regression(struct Matrix* AL, struct Matrix* Y, struct Caches* caches) {


    /*
    * Implement the backward propagation for the [LINEAR->RELU] * (L-1) -> LINEAR group
    *   AL -- probability vector, output of the forward propagation (L_model_forward())
    *   Y -- true "label" vector (containing 0 if non-cat, 1 if cat)
    *    caches -- list of caches containing:
    *          every cache of linear_activation_forward() with "relu" (it's caches[l], for l in range(L-1) i.e l = 0...L-2)
    *           the cache of linear_activation_forward() with "linear" (it's caches[L-1])
    *
    *   Returns:
    *       grads -- A dictionary with the "gradients"
    *
    *
    */
    struct GradientsContainer* grads = create_GradientsContainer(caches->num_caches);

    int L = caches->num_caches; //Number of layers - 1 e.g number parameters

    //initialize the backpropagation

    struct Matrix* dAL = matrix_matrix_operation(AL,Y,subtract); //AL-Y


    //Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "AL, Y, caches". Outputs: "grads["dAL"], grads["dWL"], grads["dbL"]
    struct Derivative_Cache* currentcache = linear_activation_backward(dAL, caches->cache[L-1], 'l');
    free_mat(dAL);
    grads->grads[L-1]->dA_prev = currentcache->dA_prev;
    grads->grads[L-1]->dW = currentcache->dW;
    grads->grads[L-1]->db = currentcache->db;
    free(currentcache);



    for (int i = L-2; i >= 0 ; --i) {

        currentcache = linear_activation_backward(grads->grads[i+1]->dA_prev, caches->cache[i], 't');
        grads->grads[i]->dA_prev = currentcache->dA_prev;
        grads->grads[i]->dW = currentcache->dW;
        grads->grads[i]->db = currentcache->db;
        free(currentcache);
    }


    return grads;
}


#endif //NEURALNETWORKLIB_LMODELBACKWARDCLASSIFICATION_H
