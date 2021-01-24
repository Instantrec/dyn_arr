#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct {
    char *key;
    char *value;
} ht_record;

typedef struct {
    int size;
    int count;
    ht_record **records;
} hash_table;

#endif