#ifndef PPRINT_H__
#define PPRINT_H__

#include <stdio.h>
#include "Vector.h"

void printFloat(float *fl);
void printInteger(int *in);
void printChar(char *c);
void printString(char *s);
void printIntArray(int* arr, int size);
void printFloatArray(float* arr, int size);
void printType(void* data, int size, int type);



#endif // PPRINT_H__