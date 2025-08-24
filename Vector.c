#include "Vector.h"


Vec* createVector(){
    Vec* vector = (Vec*)malloc(sizeof(Vec));
    vector->capacity = 1;
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
    for (int i = 0; i < vector->count; ++i){
        assert((vector->objects)[i] != NULL);
        free((vector->objects)[i]);
    }
    free(vector->objects);
    free(vector);
}

void printVector(const Vec* vector){
    if (vector->count == 0) {
        printf("{}\n");
        return;
    }
    printf("{");
    for (int i = 0; i < vector->count - 1; i++){
        Object* obj = vector->objects[i];
        printType(obj->data, obj->size, obj->ObjectType);
        printf(", ");
    
    }
    Object* obj = vector->objects[vector->count - 1];
    printType(obj->data, obj->size, obj->ObjectType);
    printf("}\n");
};

void _appendVec(Vec* vector, void* data, int size, enum ObjType type){
    assert(data!= NULL);
    assert(INTEGER <= type <= FLOAT_ARRAY);
    if(vector->capacity == vector->count){
        _resizeVec(vector);
    }
    vector->objects[vector->count]->ObjectType = type;
    vector->objects[vector->count]->data = data;
    vector->objects[vector->count]->size = size;

    ++(vector->count);
}

void* popVector(Vec* vector){
    assert(vector->count != 0);
    void *data = vector->objects[vector->count - 1]->data;
    assert(data != NULL);
    --(vector->count);
    return data;
}

void _insertVec(Vec* vector, int index, void* data, int size, enum ObjType type){
    assert(data!= NULL);
    assert(INTEGER <= type <= FLOAT_ARRAY);
    assert(0 <= index<= vector->count);
    if(index == vector->count){
        _appendVec(vector, data, size, type);
        return;
    }
    if(vector->capacity == vector->count){
        _resizeVec(vector);
    }
    ++(vector->count);
    memmove(&vector->objects[index+1], &vector->objects[index], (vector->count - index)*sizeof(Object*));
    
    vector->objects[index] = (Object*)malloc(sizeof(Object));
    assert(vector->objects[index] != NULL);
    
    vector->objects[index]->ObjectType = type;
    vector->objects[index]->data = data;
    vector->objects[index]->size = size;
}

void _resizeVec (Vec* vector){
    vector->objects = (Object**) realloc(vector->objects, vector->capacity * sizeof(Object*) *2);
    assert(vector->objects != NULL);
    for (int i = vector->capacity; i < vector->capacity*2; ++i){
        (vector->objects)[i] = (Object*) malloc(sizeof(Object));
        assert((vector->objects)[i]!= NULL);
    }
    vector->capacity *= 2;
}

int lenVector(const Vec* vector){
    return vector->count;
}

void* getVector(const Vec* vector, int index, int* datatype, int* size){
    assert(index <= vector->count - 1);
    void *data = (void*) vector->objects[index]->data;
    assert(data != NULL);

    *datatype = vector->objects[index]->ObjectType;
    *size = vector->objects[index]->size;
    return data;
}