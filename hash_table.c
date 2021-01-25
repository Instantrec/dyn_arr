#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "hash_table.h"

static ht_item *ht_new_record(const char *k, const char *v)
{
    ht_item *i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

ht_hash_table *ht_new()
{
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));

    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));

    return ht;
}

static void ht_del_item(ht_item* i)
{
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table *ht)
{
    for (uint32_t i = 0; i < ht->size; ++i)
    {
        ht_item *item = ht->items[i];
        if (item != NULL)
        {
            ht_del_item(item);
        }
    }
}

// HASH FUNCTION
static int ht_hash(const char *s, const int a, const int m)
{
    int64_t hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; ++i)
    {
        //hash = (int64_t)pow(1, 2);
        hash += (int64_t)pow(a, len_s - (i + 1)) * s[i];
        hash %= m;
    }
    
    return (int)hash;
}