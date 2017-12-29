//
// Created by Sebastian Lettner on 09.12.17.
//

#ifndef NEURALNETWORK_READINPUT_H
#define NEURALNETWORK_READINPUT_H

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

struct Input* create_Input(double trainings_examples[1000][2], int labels[1000], double tests[1000][2],
                            int num_examples, int num_tests) {

    struct Input* input = (struct Input*)malloc(sizeof(struct Input));
    struct Matrix* X = create_matrix(2,num_examples);
    struct Matrix* Y = create_matrix(1,num_examples);
    struct Matrix* T = create_matrix(2,num_tests);
    for (int i = 0; i < num_examples; ++i) {
        X->matrix[0][i] = trainings_examples[i][0];
        X->matrix[1][i] = trainings_examples[i][1];
        Y->matrix[0][i] = (double)labels[i];

    }
    for (int i = 0; i < num_tests ; ++i) {
        T->matrix[0][i] = tests[i][0];
        T->matrix[1][i] = tests[i][1];
    }
    input->num_examples = num_examples;
    input->num_tests = num_tests;
    input->T = T;
    input->X = X;
    input->Y = Y;
    return input;

}


struct Input* read_input_classification() {

    double training_set[1000][2];
    int labels[1000];
    double tests[1000][2];



    for(int i = 0; i<1000; i++) {

        labels[i] = 0; //init with zeros

        for (int j = 0; j<2; j++) {
                training_set[i][j] = 0; //first column ones
                tests[i][j] = 0;
            }
    }



    char inputLine[50];
    char delimiter[] = ",";
    char *ptr;
    int j,count = 0;
    int i = 0;

    while(scanf("%s\n", inputLine) != EOF) {

        ptr = strtok(inputLine, delimiter);
        j = 1;
        count = 0;
        while(ptr != NULL) {

            double num = atof(ptr);

            //check for zero
            if (((int)num) == 0) {
                count++;
            }

            //fill in trianing_set
            if( j==1 || j==2) {
                training_set[i][j-1] = num;
            }
            if( j==3) {
                if((int)num == -1) {
                    num  =  0;
                }
                labels[i] = (int)num;
            }
            // naechsten Abschnitt erstellen
            ptr = strtok(NULL, delimiter);
            j++;
        }
        if(count == 3) {break;}//detect triple zero
        i++;
    }
    int num_training_examples = i;
    i = 0;
    while(scanf("%s\n", inputLine) != EOF) {


        ptr = strtok(inputLine, delimiter);
        j = 1;
        while(ptr != NULL) {

            double num = atof(ptr);

            //fill in trianing_set
            tests[i][j-1] = num;
            // naechsten Abschnitt erstellen
            ptr = strtok(NULL, delimiter);
            j++;
        }
        i++;
    }
    int num_test_examples = i;
    return create_Input(training_set,labels,tests,num_training_examples,num_test_examples);
}



#endif //NEURALNETWORK_READINPUT_H
