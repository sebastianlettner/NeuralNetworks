//
// Created by Sebastian Lettner on 10.12.17.
//

#ifndef NEURALNETWORK_WRITEPREDICTIONSTOFILE_H
#define NEURALNETWORK_WRITEPREDICTIONSTOFILE_H

#include "../Parameters/InitializeParameters.h"
#include "predict.h"

void write_to_file(struct ParametersContainer* parameters) {

    struct Matrix* test = create_matrix(1,2001);

    double val = -10.0;

    for (int i = 0; i < 2001; ++i) {
        test->matrix[0][i] = val + (i/(double)100);

    }


    struct Vector* predictions = predict_regression(test,parameters);

    FILE *f = fopen("/Users/sebastianlettner/Google Drive/MaschineLearning/NeuralNetworkLib/NeuralNetworkLib/file.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int j = 0; j < predictions->dim; ++j) {
        fprintf(f,"%f\n",predictions->vec[j]);
    }
    fclose(f);

}

#endif //NEURALNETWORK_WRITEPREDICTIONSTOFILE_H
