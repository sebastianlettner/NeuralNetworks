//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_CACHE_H
#define NEURALNETWORK_CACHE_H



#include <stdlib.h>
#include "../Helpers/Matrix.h"
#include "../Helpers/Vector.h"


typedef struct Cache {


    struct Matrix* A_prev; //Activations of previous layer
    struct Matrix* W; //W parameter of current layer
    struct Vector* b; //b parameter of current layer
    struct Matrix* Z; //post activation value of current layer

} Cache;

struct Cache* create_cache(struct Matrix* A_prev,struct Matrix* W,struct Vector* b, struct Matrix* Z) {

    struct Cache* cache = (struct Cache*)malloc(sizeof(struct Cache));
    cache->A_prev = A_prev;
    cache->W = W;
    cache->b = b;
    cache->Z = Z;
    return cache;

}
#endif //NEURALNETWORK_CACHE_H
