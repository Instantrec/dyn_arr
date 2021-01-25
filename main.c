#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "dyn_array.h"
#include "hash_table.h"

int main()
{
    printf("Hash table demo\n");

    ht_hash_table* ht = ht_new();
    ht_del_hash_table(ht);
    /*printf("Dynamic Array demo\n");

    dynArr *arr;
    arr = malloc(sizeof(dynArr));

    int vals[] = {1, 2, 3};
    init(arr, vals, ARRSIZE(vals));

    int insertVals[] = {10, 20, 30};
    insert(arr, insertVals, ARRSIZE(insertVals), 0);
    printInfo(*arr);

    insert(arr, insertVals, ARRSIZE(insertVals), 0);
    printInfo(*arr);*/

    /*add(arr, 4);
    printInfo(*arr);

    addValues(arr, vals, ARRSIZE(vals));
    printInfo(*arr);

    set(arr, 228, 3);
    printInfo(*arr);

    int insertVal = 10;
    insert(arr, &insertVal, 1, 0);
    printInfo(*arr);*/

    //deleteArr(arr);

    return EXIT_SUCCESS;
}
