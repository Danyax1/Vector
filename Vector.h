#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <assert.h>

enum ObjType {
    INTEGER,
    FLOAT,
    CHAR,
    STRING,
    ARRAY
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
#endif //VECTOR_H_