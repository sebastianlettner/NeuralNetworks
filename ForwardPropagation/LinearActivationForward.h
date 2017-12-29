//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_LINEARACTIVATIONFORWARD_H
#define NEURALNETWORK_LINEARACTIVATIONFORWARD_H

#include "LinearForward.h"
#include "../Helpers/Matrix.h"
#include "../Caches/Cache.h"
#include "../ActivationFunctions/Sigmoid.h"
#include "../ActivationFunctions/TangensHyperbolikus.h"
#include "../ActivationFunctions/RectifiedLinearUnit.h"
#include "../ActivationFunctions/Linear.h"

typedef struct Intermediate_Cache {

    struct Matrix* A;
    struct Cache* cache;

}Intermediate_Cache;


struct Intermediate_Cache* create_intermediate_cache(struct Matrix* A, struct Cache* cache) {

    struct Intermediate_Cache* int_c = (struct Intermediate_Cache*)malloc(sizeof(Intermediate_Cache));
    int_c->cache = cache;
    int_c->A = A;
    return int_c;

}

struct Intermediate_Cache* linear_activation_forward(struct Matrix* A_prev, struct Matrix* W, struct Vector* b, const char activation) {

    /*
    Implement the forward propagation for the LINEAR->ACTIVATION layer

            Arguments:
    A_prev -- activations from previous layer (or input data): (size of previous layer, number of examples)
    W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
    b -- bias vector, numpy array of shape (size of the current layer, 1)
    activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"

    Returns:
    A -- the output of the activation function, also called the post-activation value
    cache -- a python dictionary containing "linear_cache" and "activation_cache";
    stored for computing the backward pass efficiently
    */



    if (activation == 's') {

        struct Cache*  cache = linear_forward(A_prev,W,b);
        struct Matrix* A = sigmoid_mat(cache->Z);
        return create_intermediate_cache(A,cache);
    }

    if (activation == 'r') {
        struct Cache*  cache = linear_forward(A_prev,W,b);
        struct Matrix* A = relu_mat(cache->Z);
        return create_intermediate_cache(A,cache);
    }

    if (activation == 't') {
        struct Cache*  cache = linear_forward(A_prev,W,b);
        struct Matrix* A = tanh_mat(cache->Z);
        return create_intermediate_cache(A,cache);
    }
    if (activation == 'l') {

        struct Cache*  cache = linear_forward(A_prev,W,b);
        struct Matrix* A = linear_mat(cache->Z);
        return create_intermediate_cache(A,cache);
    }
    else {
        printf("Unknown activation");
        return create_intermediate_cache(create_matrix(1,1),linear_forward(A_prev,W,b));
    }

}



#endif //NEURALNETWORK_LINEARACTIVATIONFORWARD_H
