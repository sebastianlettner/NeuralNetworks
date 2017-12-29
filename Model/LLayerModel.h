//
// Created by Sebastian Lettner on 08.12.17.
//

#ifndef NEURALNETWORK_LLAYERMODEL_H
#define NEURALNETWORK_LLAYERMODEL_H

#include "UpdateParameters.h"
#include <stdbool.h>
#include "../CostFunction/ComputeCost.h"
#include "../ForwardPropagation/LModelForward.h"
#include "../Predict/predict.h"


struct ParametersContainer* l_layer_model(struct Matrix* X, struct Matrix* Y, int num_layers,
                                          const int* layer_dims, double learning_rate,
                                          int num_iterations, double lambda, bool print_cost) {


    struct ParametersContainer* parameters = initialize_weights(num_layers,layer_dims);

    for (int i = 1; i <= num_iterations; ++i) {

        struct Intermediate_Cache_L* int_c_L = L_model_forward_regression(X,parameters);

        double cost_iter = compute_cost_regression(int_c_L->AL,Y);

        struct GradientsContainer* grads = L_model_backward_regression(int_c_L->AL, Y, int_c_L->caches);

        parameters = update_parameters(parameters,grads,lambda,learning_rate,i);

        if (print_cost==true && i%100==0) {
            printf("Cost after Iteration %d: %f\n", i, cost_iter);
            /*
            printf("Predictions : ");
            struct Vector* predictions = predict_regression(X, parameters);
            print_vec(predictions);
            */
        }

        /* DEALLOCATION */
        for (int j = 0; j < num_layers-1; ++j) {
            free_mat(int_c_L->caches->cache[j]->W);
            free_mat(int_c_L->caches->cache[j]->Z);
            free_mat(int_c_L->caches->cache[j]->A_prev);
            free_vec(int_c_L->caches->cache[j]->b);

            free_mat(grads->grads[j]->dA_prev);
            free_mat(grads->grads[j]->dW);
            free_vec(grads->grads[j]->db);
        }
        free_mat(int_c_L->AL);
        free(int_c_L->caches->cache);
        free(int_c_L->caches);
        free(int_c_L);
        free(grads->grads);
        free(grads);

    }





    return parameters;
}


#endif //NEURALNETWORK_LLAYERMODEL_H
