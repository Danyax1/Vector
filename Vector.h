#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "pprint.h"


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
void _resizeVec (Vec* vector);
void printVector(const Vec* vector);

void appendVector(Vec* vector, void* data, int size, enum ObjType type);
void* popVector(Vec* vector);
void insertVector(Vec* vector, int index, void* data, int size, enum ObjType type);
void removeVector(Vec* vector, int index);

int lenVector(const Vec* vector);
void* getVector(const Vec* vector, int index, int* datatype, int* size);

void copyVector(const Vec* src, Vec* dest);
#endif //VECTOR_H_