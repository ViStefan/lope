#include <stdlib.h>
#include <stdio.h>

#include "hash.h"
#include "list.h"

#define HASH_SIZE 1024

struct Hash
{
    List *h;
};

typedef struct Pair *Pair;
struct Pair
{
    KEY_T k;
    void *v;
};

int hash(KEY_T k)
{
    int i = 1;
    while (*k) i += *k++; /* sum up all char values of key */
    return i % HASH_SIZE;
}

void Hash_add(Hash *h, KEY_T k, void *i)
{
    if (!*h) /* initialize list if NULL */
    {
        *h = (Hash)calloc(sizeof(List *) * HASH_SIZE + sizeof(Hash), 1);
        (*h)->h = (List *)((*h) + 1);
    }
    Pair p = malloc(sizeof(struct Pair));
    p->k = k;
    p->v = i;
    List_add(&(*h)->h[hash(k)], p);

}

bool by_key(void *k, void *i)
{
    return ((Pair)i)->k == (KEY_T)k;
}

void *Hash_get(Hash *h, KEY_T k)
{
    return ((Pair)(List_get(&(*h)->h[hash(k)], &by_key, k)))->v;
}

void Hash_remove(Hash *h, KEY_T k)
{
    List_remove(&(*h)->h[hash(k)], Hash_get(h, k));
}

void Hash_free(Hash *h)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if ((*h)->h[i])
        {
            /* deep to free Pairs in List nodes */
            List_free(&(*h)->h[i], DEEP);
        }
    }
    free(*h);
}
