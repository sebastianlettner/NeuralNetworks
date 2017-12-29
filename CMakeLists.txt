cmake_minimum_required(VERSION 3.8)
project(NeuralNetwork)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c
        Parameters/Parameters.h
        Parameters/InitializeParameters.h
        Helpers/Matrix.h
        ForwardPropagation/LinearForward.h
        Caches/Cache.h
        Caches/Caches.h
        Helpers/Vector.h
        Helpers/MatrixOperations/MatrixMatrixMultiplikation.h
        Helpers/VectorOperations/VectorVectorAddition.h
        Helpers/MatrixOperations/MatrixVectorBroadcastAddtion.h
        ForwardPropagation/LinearActivationForward.h
        ActivationFunctions/RectifiedLinearUnit.h
        ActivationFunctions/TangensHyperbolikus.h
        ActivationFunctions/Sigmoid.h
        ActivationFunctions/Linear.h
        CostFunction/ComputeCost.h
        Helpers/Sum.h
        Helpers/MatrixOperations/MatrixElementOperation.h
        Helpers/Operations/operations.h
        ForwardPropagation/LModelForward.h
        BackPropagation/LinearBackward.h
        Helpers/MatrixOperations/Transpose.h
        Helpers/MatrixOperations/PrintMatrix.h
        Helpers/VectorOperations/VectorElementOperation.h
        Helpers/VectorOperations/PrintVec.h
        BackPropagation/LinearActivationBackward.h
        BackPropagation/LModelBackward.h
        Model/LLayerModel.h
        Model/UpdateParameters.h
        Input/ReadInputClassification.h
        Input/ReadInputRegression.h
        Helpers/MatrixOperations/CopyMatrix.h
        Predict/predict.h
        Predict/WritePredictionsToFile.h
        Predict/compute_error.h
        all_in_one_feel_the_pain.h
        check_mem.h
        )


add_executable(NeuralNetwork ${SOURCE_FILES})