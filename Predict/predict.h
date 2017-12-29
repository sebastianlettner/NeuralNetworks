//
// Created by Sebastian Lettner on 10.12.17.
//


#ifndef NEURALNETWORK_PREDICT_H
#define NEURALNETWORK_PREDICT_H

#include "../Helpers/Matrix.h"
#include "../Parameters/InitializeParameters.h"
#include "../ForwardPropagation/LModelForward.h"


struct Vector* predict_classification(struct Matrix* X, struct ParametersContainer* parameters) {

    struct Intermediate_Cache_L* int_c_l = L_model_forward_classification(X,parameters);
    struct Vector* predictions = create_Vector(int_c_l->AL->dim2);

    for (int i = 0; i < int_c_l->AL->dim1 ; ++i) {
        for (int j = 0; j < int_c_l->AL->dim2 ; ++j) {

            if (int_c_l->AL->matrix[i][j] >= 0.5) {
                predictions->vec[j] = 1;
            }
            else {
                predictions->vec[j] = -1;
            }
        }
    }
    return predictions;

}

struct Vector* predict_regression(struct Matrix* X, struct ParametersContainer* parameters) {


    struct Intermediate_Cache_L* int_c_l = L_model_forward_regression(X,parameters);
    struct Vector* predictions = create_Vector(int_c_l->AL->dim2);

    for (int i = 0; i < int_c_l->AL->dim1 ; ++i) {
        for (int j = 0; j < int_c_l->AL->dim2 ; ++j) {
            predictions->vec[j] = int_c_l->AL->matrix[i][j];

        }
    }
    return predictions;

}


#endif //NEURALNETWORK_PREDICT_H
