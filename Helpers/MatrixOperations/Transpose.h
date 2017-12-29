//
// Created by ga63fiy on 12/8/17.
//

#ifndef NEURALNETWORKLIB_TRANSPOSE_H
#define NEURALNETWORKLIB_TRANSPOSE_H

#include "../Matrix.h"

struct Matrix* mat_transpose(struct Matrix* A) {

    int n = A->dim1;
    int m = A->dim2;

    struct Matrix* A_trans = create_matrix(m,n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A_trans->matrix[j][i] = A->matrix[i][j];
        }
    }
    return A_trans;

}

#endif //NEURALNETWORKLIB_TRANSPOSE_H
