//
// Created by Sebastian Lettner on 09.12.17.
//

#ifndef NEURALNETWORK_READINPUTREGRESSION_H
#define NEURALNETWORK_READINPUTREGRESSION_H


#include "../Helpers/Matrix.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Input {

    int num_examples;
    int num_tests;
    struct Matrix* X;
    struct Matrix* Y;
    struct Matrix* T;

} Input;

struct Input* create_Input(double trainings_examples[1000], double labels[1000], double tests[1000],
                           int num_examples, int num_tests) {

    struct Input* input = (struct Input*)malloc(sizeof(struct Input));
    struct Matrix* X = create_matrix(1,num_examples);
    struct Matrix* Y = create_matrix(1,num_examples);
    struct Matrix* T = create_matrix(1,num_tests);

    for (int i = 0; i < num_examples; ++i) {
        X->matrix[0][i] = trainings_examples[i];
        Y->matrix[0][i] = labels[i];

    }
    for (int i = 0; i < num_tests ; ++i) {
        T->matrix[0][i] = tests[i];
    }
    input->num_examples = num_examples;
    input->num_tests = num_tests;
    input->T = T;
    input->X = X;
    input->Y = Y;
    return input;

}

struct Input* create_input_2(struct Matrix* X,struct Matrix*Y,struct Matrix* T, int num_ex, int num_test) {

    struct Input* input = (struct Input*)malloc(sizeof(struct Input));
    input->num_examples = num_ex;
    input->num_tests = num_test;
    input->T = T;
    input->X = X;
    input->Y = Y;
    return input;


}

struct Input* get_example_input() {

    double training_set[30];
    double labels[30];
    double tests[5] = {1,2,3,4,5};
    int num_training_examples = 30;
    int num_test_examples =  5;



    for(int i = 0; i<30; i++) {

        labels[i] = 0;
        training_set[i] = 0;
    }

    double all[60] = {10.3731,-1.8691, 9.6259,-3.0553, 9.7475,-2.8169, -15.7632,11.8786, 7.2624,-7.3586, -1.4696,-2.6917, -11.5135,1.8409, -16.0593,11.9093, 12.943,-5.0448, -12.9996,5.2224, -13.4572,6.7097, 6.6395,-7.3114, 15.7756,-11.8833, 0.66233,1.4576, 8.1081,-6.3374, -13.8564,8.0132, 18.1383,-8.5489, 1.6354,2.8248, 7.1894,-7.3914, -18.5375,7.6748, 12.3682,-3.408, 9.9448,-2.463, -15.1925,11.3387, 1.0018,2.0798, -6.9667,7.4295, 1.858,2.9259, -4.0448,0.80118, -3.3963,-1.0697, -12.7705,4.5189, -9.7845,2.7473};

    for (int j = 0; j < 60; ++j) {
        if (j==0) {
            training_set[j] = all[0];
        }
        if (j%2 == 0) {
            training_set[j] = all[j];
        }
        else{
            labels[j] = all[j];
        }
    }


    return create_Input(training_set,labels,tests,num_training_examples,num_test_examples);


}

struct Input* read_input_regression() {

    double training_set[1000];
    double labels[1000];
    double tests[1000];



    for(int i = 0; i<1000; i++) {

        labels[i] = 0;
        training_set[i] = 0;
        tests[i] = 0;
    }


    char inputLine[50];
    char delimiter[] = ",";
    char *ptr;
    int j,count = 0;
    int i = 0;

    while(scanf("%s\n", inputLine) != EOF) {

        ptr = strtok(inputLine, delimiter);
        j = 0;
        count = 0;
        while (ptr != NULL) {

            double num = atof(ptr);

            //check for zero
            if ((num) == 0) {
                count++;
            }

            //fill in trianing_set
            if (j == 0) {
                training_set[i] = num;
            }
            if (j == 1) {
                labels[i] = num;
            }
            // nächsten Abschnitt erstellen
            ptr = strtok(NULL, delimiter);
            j++;
        }
        if (count == 2) { break; }//detect double zero
        i++;
    }
    int num_training_examples = i;
    i = 0;
    while (scanf("%s\n", inputLine) != EOF) {

        ptr = strtok(inputLine, delimiter);
        j = 1;
        while (ptr != NULL) {

            double num =atof(ptr);
            //fill in trianing_set
            tests[i] = num;
            // naechsten Abschnitt erstellen
            ptr = strtok(NULL, delimiter);
            j++;
        }
        i++;
    }
    int num_test_examples = i;

    return create_Input(training_set,labels,tests,num_training_examples,num_test_examples);
// initialisieren und ersten Abschnitt erstellen


}
#endif //NEURALNETWORK_READINPUTREGRESSION_H
