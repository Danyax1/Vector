#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <assert.h>

#include "pprint.h"

#define __GET_SIZE(data, type) \
    ((type) == STRING ? strlen((char*)(data)) : \
    ((type) == INT_ARRAY ? sizeof(data)/sizeof(int) : \
    ((type) == FLOAT_ARRAY ? sizeof(data)/sizeof(float) : 1)))

// Main macro: vec, data, type
#define appendVector(vec, data, type) \
    _appendVec((vec), (data), __GET_SIZE((data), (type)), (type))


enum ObjType {
    INTEGER,
    FLOAT,
    CHAR,
    STRING,
    INT_ARRAY,
    FLOAT_ARRAY
};

typedef struct{
    int ObjectType;
    int size;
    void* data;
}Object;

typedef struct {
    Object** objects;
    int count;
    int capacity;
}Vec;


Vec* createVector();
void freeVector(Vec* vector);
void printVector(const Vec* vector);
void _resizeVec (Vec* vector);

void _appendVec(Vec* vector, void* data, int size, enum ObjType type);
void* popVector(Vec* vector);

int lenVector(const Vec* vector);
void* getVector(const Vec* vector, int index, int* datatype, int* size);
#endif //VECTOR_H_