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

void printVector(const Vec* vector){
    printf("{");
    for (int i = 0; i < vector->count - 1; i++){
        Object* obj = vector->objects[i];
        switch (obj->ObjectType){
            case INTEGER:
                printInteger(obj->data);
                break;
            case FLOAT:
                printFloat(obj->data);
                break;
            case CHAR:
                printChar(obj->data);
                break;
            case STRING:
                printString(obj->data);
                break;
            case INT_ARRAY:
                printIntArray(obj->data, obj->size);
                break;
            case FLOAT_ARRAY:
                printFloatArray(obj->data, obj->size);
                break;
            default:
                printf("Invalid type\n");
        }
        printf(", ");
    
    }
    Object* obj = vector->objects[vector->count - 1];
    switch (obj->ObjectType){
        case INTEGER:
            printInteger(obj->data);
            break;
        case FLOAT:
            printFloat(obj->data);
            break;
        case CHAR:
            printChar(obj->data);
            break;
        case STRING:
            printString(obj->data);
            break;
        case INT_ARRAY:
            printIntArray(obj->data, obj->size);
            break;
        case FLOAT_ARRAY:
            printFloatArray(obj->data, obj->size);
            break;
        default:
            printf("Invalid type\n");
    }
    printf("}\n");
};

void _appendVec(Vec* vector, void* data, int size, enum ObjType type){
    if(vector->capacity == vector->count){
        printf("Vector is full, need resizing\n");
        return;
    }
    vector->objects[vector->count]->ObjectType = type;
    vector->objects[vector->count]->data = data;
    vector->objects[vector->count]->size = size;

    (vector->count)++;
}