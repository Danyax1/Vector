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

void freeVector(Vec* vector){
    for (int i = 0; i < vector->capacity; ++i){
        if(!(vector->objects)[i]->data){
            free((vector->objects)[i]->data);
        }
        assert((vector->objects)[i] != NULL);
        free((vector->objects)[i]);
    }
    free(vector->objects);
    free(vector);
}

void appendVector(Vec* vector, void* data, enum ObjType type){
    if(vector->capacity == vector->count){
        printf("Vector is full, need resizing/n");
        return;
    }
    vector->objects[vector->count]->ObjectType = type;
    vector->objects[vector->count]->data = data;

    (vector->count)++;
}