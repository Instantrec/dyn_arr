#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ARRSIZE(x) sizeof(x) / sizeof((x)[0])

#define SUCCESS 0
#define FAILURE 1

typedef struct {
    /*
    array[0:size - 1] has values
    array[size:fullsize] will have later
    */
    int size;
    int fullsize;
    int *el;
} dynArr;

void printInfo(dynArr arr);


int init(dynArr *arr, int values[], int size);
void deleteArr(dynArr *arr);

int add(dynArr *arr, int value);
int addValues(dynArr *arr, int values[], int size);

int set(dynArr *arr, int el, uint32_t index);

int insert(dynArr *arr, int *vals, size_t amount, uint32_t pos);

#endif