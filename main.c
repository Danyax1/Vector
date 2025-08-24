#include "Vector.h"

#include <stdio.h>
#include <string.h>


#define arrlen(arr) sizeof(arr)/sizeof((arr)[0])



int main(void){
    int x = 10;
    float y = 3.14f;
    char c = 'A';
    char *str = "Hello World";
    int arrInt[] = {1, 2, 3, 4, 5};
    float arrFloat[] = {1.1, 2.2, 3.3};

    


    Vec* my_list = createVector();
    
    printVector(my_list);
    appendVector(my_list, &x, INTEGER);
    appendVector(my_list, &y, FLOAT);
    appendVector(my_list, str, STRING);
    appendVector(my_list, arrInt, INT_ARRAY);
    appendVector(my_list, arrFloat, FLOAT_ARRAY);
    appendVector(my_list, &c, CHAR);


    printVector(my_list);
    printf("Len of my_list: %d\n", lenVector(my_list));
    popVector(my_list);
    // printVector(my_list);

    // printf("Len of my_list: %d\n", lenVector(my_list));

    int datatype;
    int size;
    void* floats = getVector(my_list, 4, &datatype, &size);

    // printf("size: %d\n",size);
    // printFloatArray(floats, size);
    // printf("\n");

    printf("Before inserting\n");

    printVector(my_list);

    insertVector(my_list, 2, &x, INTEGER);
    printf("After inserting\n");
    printVector(my_list);

    removeVector(my_list, 2);

    insertVector(my_list, 2, &x, INTEGER);

    removeVector(my_list, 3);

    printVector(my_list);
    return 0;
}