//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_INITIALIZEPARAMETERS_H
#define NEURALNETWORK_INITIALIZEPARAMETERS_H

#include "Parameters.h"

double double_rand(double min, double max) {


    double scale = (double)rand() / (double) RAND_MAX;
    return min + scale * (max-min);

}

struct ParametersContainer* initialize_weights(int num_layers,const int* layer_dims) {

    /*
     * Function creating and initializing the weigths
     * Args:
     *      num_layers: the total amount of layers (also counting out/in)
     *      layer_dims: number of hidden units in each layer
     *
     * return:
     *      pointer to Parameters. Containing holding all created parameters
     */

    struct ParametersContainer* parameters = (struct ParametersContainer *) malloc(sizeof(struct ParametersContainer));
    parameters->parameter = (struct Parameter**)malloc((num_layers-1)*sizeof(struct Parameter*));
    for (int i = 0; i<num_layers-1 ; ++i) {
        parameters->parameter[i] = (struct Parameter*)malloc(sizeof(struct Parameter));
    }


    for(int i = 0; i<num_layers-1; i++) {
        //num_layer - 1 because we always have num_layer-1 sets of parameters
        int num_hidden_units_1 = layer_dims[i];
        int num_hidden_units_2 = layer_dims[i+1];

        struct Parameter* p = create_parameters(i+1,num_hidden_units_2,num_hidden_units_1,num_hidden_units_2);
        parameters->parameter[i] = p;

    }


    for (int j = 0; j < num_layers-1; ++j) {
        for (int i = 0; i < parameters->parameter[j]->W->dim1 ; ++i) {
            parameters->parameter[j]->b->vec[i] = 0;
            for (int k = 0; k < parameters->parameter[j]->W->dim2; ++k) {
                parameters->parameter[j]->W->matrix[i][k] = double_rand(-1,1);
            }
        }
    }
    parameters->num_layers = num_layers;
    return parameters;

}

#endif //NEURALNETWORK_INITIALIZEPARAMETERS_H
