//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_LMODELFORWARDCLASSIFICATION_H
#define NEURALNETWORKLIB_LMODELFORWARDCLASSIFICATION_H


#include "LinearActivationForward.h"
#include "../Caches/Caches.h"
#include "../Parameters/InitializeParameters.h"
#include "../Helpers/MatrixOperations/CopyMatrix.h"

typedef struct Intermediate_Cache_L {

    struct Matrix* AL;
    struct Caches* caches;

} Intermediate_Cache_L;


struct Intermediate_Cache_L* create_intermediate_cache_L(struct Matrix* AL, struct Caches* caches) {

    struct Intermediate_Cache_L* int_c_L = (struct Intermediate_Cache_L*)malloc(sizeof(Intermediate_Cache_L));
    int_c_L->caches = caches;
    int_c_L->AL = AL;
    return int_c_L;

}

struct Intermediate_Cache_L* L_model_forward_classification(struct Matrix* X, struct ParametersContainer* parameters) {

    /*
    Implement forward propagation for the [LINEAR->RELU]*(L-1)->LINEAR computation

    Arguments:
    X -- data, array of shape (input size, number of examples)
    parameters -- output of initialize_parameters()

    Returns:
    Intermediate_Cacghe_L:
        AL -- last post-activation value
        caches -- list of caches containing:
        every cache of linear_relu_forward() (there are L-1 of them, indexed from 0 to L-2)
        the cache of linear_sigmoid_forward() (there is one, indexed L-1)
    */

    Caches* caches = create_caches(parameters->num_layers-1);

    struct Matrix* A = copy_matrix(X);

    for (int i = 0; i < parameters->num_layers - 2 ; ++i) {
        struct Matrix* A_prev = copy_matrix(A);
        struct Intermediate_Cache* int_c = linear_activation_forward(A_prev, parameters->parameter[i]->W,parameters->parameter[i]->b,'t');
        caches->cache[i] = int_c->cache;
        A = int_c->A;

    }
    //Output Layer
    struct Intermediate_Cache* int_c = linear_activation_forward(A, parameters->parameter[parameters->num_layers-2]->W, parameters->parameter[parameters->num_layers-2]->b, 's' );
    caches->cache[parameters->num_layers-2] = int_c->cache;


    return create_intermediate_cache_L(int_c->A,caches);

}

struct Intermediate_Cache_L* L_model_forward_regression(struct Matrix* X, struct ParametersContainer* parameters) {

    /*
    Implement forward propagation for the [LINEAR->RELU]*(L-1)->LINEAR computation

    Arguments:
    X -- data, array of shape (input size, number of examples)
    parameters -- output of initialize_parameters()

    Returns:
    Intermediate_Cacghe_L:
        AL -- last post-activation value
        caches -- list of caches containing:
        every cache of linear_relu_forward() (there are L-1 of them, indexed from 0 to L-2)
        the cache of linear_sigmoid_forward() (there is one, indexed L-1)
    */

    Caches* caches = create_caches(parameters->num_layers-1);

    struct Matrix* A = copy_matrix(X);


    for (int i = 0; i < parameters->num_layers - 2 ; ++i) {
        struct Matrix* A_prev = copy_matrix(A);
        free_mat(A);
        struct Intermediate_Cache* int_c = linear_activation_forward(A_prev, parameters->parameter[i]->W, parameters->parameter[i]->b,'t');
        caches->cache[i] = int_c->cache;
        A = int_c->A;

    }
    //Output Layer
    struct Intermediate_Cache* int_c = linear_activation_forward(A, parameters->parameter[parameters->num_layers-2]->W, parameters->parameter[parameters->num_layers-2]->b, 'l' );

    caches->cache[parameters->num_layers-2] = int_c->cache;

    return create_intermediate_cache_L(int_c->A,caches);

}


#endif //NEURALNETWORKLIB_LMODELFORWARDCLASSIFICATION_H
