//
// Created by Sebastian Lettner on 07.12.17.
//

#ifndef NEURALNETWORK_CACHES_H
#define NEURALNETWORK_CACHES_H

#include "Cache.h"

typedef struct Caches {

    struct Cache** cache;
    int num_caches;

} Caches;

struct Caches* create_caches(int num_caches) {

    struct Caches* caches = (struct Caches*)malloc(sizeof(struct Caches));
    caches->cache = (struct Cache**) malloc(sizeof(struct Cache*)*num_caches);
    for (int j = 0; j < num_caches; ++j) {
        caches->cache[j] = (struct Cache*)malloc(sizeof(struct Cache));
    }
    caches->num_caches = num_caches;
    return caches;

}

#endif //NEURALNETWORK_CACHES_H
