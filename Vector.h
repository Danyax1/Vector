#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    void* data;
}Object;

typedef struct {
    Object** objects;
    int count;
    int capacity;
}Vec;


Vec* createVector();
void freeVector(Vec* vector);

void appendVector(Vec* vector, void* data, enum ObjType type);
#endif //VECTOR_H_