#include "Model/LLayerModel.h"
#include "Input/ReadInputRegression.h"
#include "Predict/compute_error.h"
#include "Predict/WritePredictionsToFile.h"

//localmac


int main() {


    srand((unsigned int) time(NULL));

    bool print_cost = true;

    int num_iterations = 10000;

    double learning_rate = 0.001;

    int num_layers = 6;

    const int layer_dims[6] = {1,10,10,10,10,1} ;

    double lambda = 0.000;

    struct Input* input = read_input_regression();



    
    struct ParametersContainer* parameters = l_layer_model(input->X,input->Y,num_layers,layer_dims,learning_rate,num_iterations,lambda,print_cost);
    print_vec(predict_regression(input->T,parameters));

    compute_error_reg(input->num_tests,predict_regression(input->T,parameters));
    write_to_file(parameters);


    return EXIT_SUCCESS;
}