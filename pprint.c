#include "pprint.h"

void printFloat(float *fl){
    printf("%f", *fl);
}
void printInteger(int *in){
    printf("%d", *in);
}
void printChar(char *c){
    printf("%c", *c);
}
void printString(char *s){
    printf("%s", s);
}
void printIntArray(int* arr, int size){
    printf("[");
    for (int i = 0; i < size - 1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[size - 1]);
}
void printFloatArray(float* arr, int size){
    printf("[");
    for (int i = 0; i < size - 1; i++){
        printf("%f, ", arr[i]);
    }
    printf("%f]", arr[size - 1]);
}

void printType(void* data, int size, int type){
    switch (type){
        case INTEGER:
            printInteger((int*)data);
            break;
        case FLOAT:
            printFloat((float*)data);
            break;
        case CHAR:
            printChar((char*)data);
            break;
        case STRING:
            printString((char*)data);
            break;
        case INT_ARRAY:
            printIntArray((int*)data, size);
            break;
        case FLOAT_ARRAY:
            printFloatArray((float*)data, size);
            break;
        default:
            printf("Invalid type\n");
    }
}
