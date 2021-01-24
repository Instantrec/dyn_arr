#include "dyn_array.h"

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

        //arr->el = calloc(arr->size * 2, sizeof(int)); another wat to reallocate but the realloc() is considered to be used
        arr->el = (int *)realloc(arr->el, arr->size * 2);
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

int insert(dynArr *arr, int *vals, size_t amount, uint32_t pos)
{
    if (amount < 1)
    {
        perror("Incorrect amount of values\n");
        return FAILURE;
    }

    if (amount > arr->fullsize - arr->size) // reallocation is required
    {
        int requiredExtension = (amount - (arr->fullsize - arr->size));
        arr->el = realloc(arr->el, requiredExtension * sizeof(int));
        arr->fullsize += requiredExtension;
    }

    memmove(arr->el + pos + amount, arr->el + pos, (arr->size - pos) * sizeof(int));
    arr->size += amount;
    memmove(arr->el + pos, vals, amount * sizeof(int));

    return SUCCESS;
}

void deleteArr(dynArr *arr)
{
    free(arr->el);

    free(arr);
}