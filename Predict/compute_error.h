//
// Created by Sebastian Lettner on 12.12.17.
//

#ifndef NEURALNETWORK_COMPUTE_ERROR_H
#define NEURALNETWORK_COMPUTE_ERROR_H

#include <stdio.h>
#include "../Helpers/Vector.h"

void compute_error(int set, int num_test_examples, struct Vector* predicted_labels) {

    int correct_labels[20] =  {1,1,1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1};
    int correct_labels_2[50] = {+1, +1, -1, +1, -1, -1, +1, +1, +1, +1, -1, +1, -1, -1, +1, -1, +1, +1, -1, -1, -1, +1, +1, -1, +1, -1, -1, +1, +1, -1, -1, +1, -1, -1, +1, +1, -1, -1, +1, +1, -1, -1, +1, -1, -1, +1, +1, +1, +1, -1};
    int correct_labels_3[40] = {-1, +1, -1, +1, -1, +1, -1, -1, -1, -1, -1, -1, +1, +1, +1, -1, +1, -1, -1, +1, +1, +1, +1, -1, +1, +1, -1, -1, -1, +1, -1, +1, +1, +1, +1, +1, +1, -1, -1, +1};
    int error = 0;

    if(set == 1) {
        for (int i = 0; i<num_test_examples; i++) {

            if(predicted_labels->vec[i] != correct_labels[i]) {
                error++;
                printf("Error in example %d: Predicted: %d Expected: %d\n" ,i+1,(int)predicted_labels->vec[i],correct_labels[i]);
            }

        }
        printf("Number of Errors: %d\n", error);
    }
    if(set == 2) {
        for (int i = 0; i<num_test_examples; i++) {

            if(predicted_labels->vec[i] != correct_labels_2[i]) {
                error++;
                printf("Error in example %d: Predicted: %d Expected: %d\n" ,i+1,(int)predicted_labels->vec[i],correct_labels_2[i]);
            }

        }
        printf("Number of Errors: %d\n", error);
    }
    if(set == 3) {
        for (int i = 0; i<num_test_examples; i++) {

            if(predicted_labels->vec[i] != correct_labels_3[i]) {
                error++;
                printf("Error in example %d: Predicted: %d Expected: %d\n" ,i+1,(int)predicted_labels->vec[i],correct_labels_3[i]);
            }

        }
        printf("Number of Errors: %d\n", error);
    }


}

void compute_error_reg(int num_labels, struct Vector* predicted_vals) {

    double correct_labels[20] = {8.2173,
            6.4488,
            7.9663,
            -1.3338,
            -1.5458,
            -4.6142,
            -4.8515,
            7.7018,
            -4.5616,
            10.1204,
            -2.4456,
            -2.3794,
            -3.2071,
            -4.9008,
            -2.4569,
            -3.203,
            1.7132,
            3.9666,
            11.1405,
            2.0089};

    double error = 0;
    for (int i = 0; i < num_labels; ++i) {
        error += (fabs(predicted_vals->vec[i]-correct_labels[i]));

    }
    printf("Error: %f\n",error);

}


#endif //NEURALNETWORK_COMPUTE_ERROR_H
