#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

void printInfo(dynArr arr)
{
    for (int i = 0; i < arr.size; ++i)
    { 
        printf("%d ", arr.el[i]);
    }
    printf(". Size = %d Fullsize = %d\n", arr.size, arr.fullsize);
}

int init(dynArr *arr, int values[], int size)
{
    arr->size = size,
    arr->fullsize = size * 2;
    arr->el = (int *)calloc(size * 2, sizeof(int));

    if (arr->el == NULL)
    {
        perror("Too big array: unable to allocate enough memory\n");
        return FAILURE;
    }

    for (int i = 0; i < size; i++)
    {
        arr->el[i] = values[i];
    }

    printInfo(*arr);

    return SUCCESS;
}

int add(dynArr *arr, int value)
{
    if (arr->size == arr->fullsize)
    {
        // reallocating

        // saving elements to a temporary array
        int *tmpArr = calloc(arr->size, sizeof(int));
        for (int i = 0; i < arr->size; ++i)
            tmpArr[i] = arr->el[i];

        arr->el = calloc(arr->size * 2, sizeof(int));
        arr->fullsize = arr->size * 2;

        // retrieving values
        for (int i = 0; i < arr->size; ++i)
            arr->el[i] = tmpArr[i];

        free(tmpArr);
    }

    // adding a new value and updating the size
    arr->el[arr->size] = value;
    arr->size++;

    return SUCCESS;
}

int addValues(dynArr *arr, int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        add(arr, values[i]);
    }

    return SUCCESS;
}

int set(dynArr *arr, int el, uint32_t index)
{
    if (index >= arr->size)
    {
        perror("The index is outside of array's borders\n");
        return FAILURE;
    }

    arr->el[index] = el;

    return SUCCESS;
}

void delete(dynArr *arr)
{
    free(arr->el);

    free(arr);
}

int main()
{
    printf("Dynamic Array demo\n");

    dynArr *arr;
    arr = malloc(sizeof(dynArr));

    int vals[] = {1, 2, 3};
    init(arr, vals, ARRSIZE(vals));

    add(arr, 4);
    printInfo(*arr);

    addValues(arr, vals, ARRSIZE(vals));
    printInfo(*arr);

    set(arr, 228, 3);
    printInfo(*arr);

    delete(arr);

    return EXIT_SUCCESS;
}