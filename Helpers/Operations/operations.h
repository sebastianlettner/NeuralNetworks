//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_ADD_H
#define NEURALNETWORKLIB_ADD_H

#include <stdio.h>

double add(double a, double b) {
    
    return a+b;
    
}

double multiply(double a, double b) {
    
    return a*b;
    
}

double subtract(double a, double b) {

    return a-b;

}

double divide(double a, double b) {

    if (b != 0) {
        return a/b;
    }
    else {
        printf("DIVIDING BY 0\n");
        return 10000;
    }
}
#endif //NEURALNETWORKLIB_ADD_H
