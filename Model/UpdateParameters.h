//
// Created by Sebastian Lettner on 08.12.17.
//

#ifndef NEURALNETWORK_UPDATEPARAMETERS_H
#define NEURALNETWORK_UPDATEPARAMETERS_H

#include "../BackPropagation/LModelBackward.h"

struct ParametersContainer* update_parameters(struct ParametersContainer* parameters, struct GradientsContainer* grads, double lambda,
                                              double learning_rate, int iteration) {



    int L = parameters->num_layers;
    for (int i = 0; i < L-1 ; ++i) {
        //Update W
        if (iteration<1000) {
            learning_rate = 0.01;
        }
        struct Matrix* dW_L = matrix_element_number_operation(parameters->parameter[i]->W,lambda,multiply);

        struct Matrix* temp = matrix_matrix_operation(grads->grads[i]->dW,dW_L,add);
        struct Matrix* temp1 = matrix_element_number_operation(temp,learning_rate,multiply);
        parameters->parameter[i]->W = matrix_matrix_operation(parameters->parameter[i]->W,temp1,subtract);
        //Update b
        struct Vector* temp2 = vector_element_number_operation(grads->grads[i]->db,learning_rate,multiply);
        parameters->parameter[i]->b = vector_vector_operation(parameters->parameter[i]->b,temp2,subtract);
        free(temp);
        free_mat(temp1);
        free_vec(temp2);

    }
    return parameters;
}


#endif //NEURALNETWORK_UPDATEPARAMETERS_H
