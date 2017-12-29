//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_COMPUTECOSTREGRESSION_H
#define NEURALNETWORKLIB_COMPUTECOSTREGRESSION_H

#include "../ForwardPropagation/LModelForward.h"
#include "../Helpers/Sum.h"
#include "../Helpers/MatrixOperations/MatrixElementOperation.h"

double compute_cost_regression(struct Matrix* AL, struct Matrix* Y) {

    /*
     * Computing cost with quadratic error loss function
     *
     * Args:
     *      AL(Matrix): dim1 = 1 dim2 = num_training_examples
     *      Contains the forward propagation output for every example
     *      Y(Matrix): dim1 = 1 dim2 = num_trainings_examples
     *      Contains ground truth labels (continuous values for regression)
     * Retruns:
     *      Cost(double)
     */

    //Using quadratic error

    double cost = 0;
    double num_training_examples = (double)AL->dim2;

    struct Matrix* temp = matrix_matrix_operation(Y,AL,subtract);
    struct Matrix* temp1 = matrix_matrix_operation(temp,temp,multiply);


    struct Vector* temp2 = sum_mat(temp1,0);
    cost = (1/(2*num_training_examples)) * sum_vec(temp2);
    cost = sqrt(cost);

    //printf("%f\n",cost);
    free_mat(temp);
    free_mat(temp1);
    free_vec(temp2);

    return cost;


}

double compute_cost_classification(struct Matrix* AL, struct Matrix* Y) {

    /*
     * Computing cost
     *
     * Args:
     *      AL(Matrix): dim1 = 1 dim2 = num_training_examples
     *      Contains the forward propagation output for every example
     *      Y(Matrix): dim1 = 1 dim2 = num_trainings_examples
     *      Contains ground truth labels (continuous values for regression)
     * Retruns:
     *      Cost(double)
     */

    double cost = 0;
    double num_training_examples = (double)AL->dim2;

    struct Matrix* temp1 = matrix_matrix_operation(matrix_operation(AL,log),Y,multiply); //Y * log(AL)
    struct Matrix* temp2 = matrix_matrix_operation(mat_ones(Y->dim1,Y->dim2),Y,subtract); // 1-Y
    struct Matrix* temp3 = matrix_matrix_operation(mat_ones(AL->dim1,AL->dim2),AL,subtract); // 1-AL
    temp3 = matrix_operation(temp3,log); //log(1-AL)
    temp3 = matrix_matrix_operation(temp3,temp2,multiply); //(1-Y)*log(1-AL)
    temp1 = matrix_matrix_operation(temp1,temp3,add); //Y*log(AL) + (1-Y)*log(1-AL)

    struct Vector* vec = sum_mat(temp1,0);


    cost = sum_vec(vec);
    cost = cost * (-1/num_training_examples);
    free(vec);

    return cost;


}


#endif //NEURALNETWORKLIB_COMPUTECOSTREGRESSION_H
