//
// Created by Sebastian Lettner on 07.12.17.
//
#ifndef HW2_NEURALNETWORK_H
#define HW2_NEURALNETWORK_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "../Helpers/Matrix.h"
#include "../Helpers/Vector.h"

typedef struct Parameter {
    //This structure hold Wx and bx and the position. If weights represent mapping form
    //input to layer 1 int layer would be 1.
    int layer;

    struct Matrix* W; //Weight matrix
    struct Vector* b; //bias vector

} Parameter;

typedef struct ParametersContainer {
    //Container holding all parameters of the neural network
    struct Parameter** parameter;
    int num_layers;

} ParametersContainer;



struct Parameter* create_parameters(int layer, int dim_1_W, int dim_2_W, int dim_b) {

    /*
     * Function creates Parameters(W,b) with given size
     */

    struct Parameter *parameter = (struct Parameter *) malloc(sizeof(struct Parameter));
    parameter->layer = layer;
    parameter->W = create_matrix(dim_1_W,dim_2_W);
    parameter->b = create_Vector(dim_b);

    return parameter;


}







#endif //HW2_NEURALNETWORK_H
