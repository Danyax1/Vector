#include "Vector.h"

Vec* createVector(){
    Vec* vector = (Vec*)malloc(sizeof(Vec));
    vector->capacity = 5;
    vector->count = 0;
    assert(vector != NULL);

    vector->objects = (Object**) malloc(vector->capacity * sizeof(Object*));
    assert(vector->objects != NULL);

    for (int i = 0; i < vector->capacity; ++i){
        (vector->objects)[i] = (Object*) malloc(sizeof(Object));
        assert((vector->objects)[i]!= NULL);
    }

    return vector;
}

void freeVector();