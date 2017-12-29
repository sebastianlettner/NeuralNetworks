//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_LINEARACTIVATIONBACKWARD_H
#define NEURALNETWORKLIB_LINEARACTIVATIONBACKWARD_H

#include "LinearBackward.h"


struct Derivative_Cache* linear_activation_backward(struct Matrix* dA, struct Cache* cache, const char activation) {

    /*
     * Impelement the backward propagation for the LINEAR->ACTIVATION layer.
     * Supported activations:
     *          tanh
     *          sigmoid
     *          relu
     *
     */

    if (activation == 'r') {

        struct Matrix* dZ = relu_backward(dA,cache->Z);
        struct Derivative_Cache* d_cache = linear_backward(dZ, cache);
        return d_cache;
    }

    if (activation == 's') {

        struct Matrix* dZ = sigmoid_backward(dA,cache->Z);
        struct Derivative_Cache* d_cache = linear_backward(dZ, cache);

        return d_cache;

    }

    if (activation == 'l') {

        struct Matrix* dZ = linear_backwards(dA,cache->Z);
        struct Derivative_Cache* d_cache = linear_backward(dZ, cache);
        return d_cache;

    }

    else  {
        //must be tanh
        struct Matrix* dZ = tanh_backward(dA,cache->Z);
        struct Derivative_Cache* d_cache = linear_backward(dZ, cache);
        return d_cache;

    }


}

#endif //NEURALNETWORKLIB_LINEARACTIVATIONBACKWARD_H
