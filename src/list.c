#include "list.h"

struct List
{
    void *v;
    List *next;
};

void List_add(List l, void *i)
{
    if (!l)
    {
        /* same problem as with hash
           should assign external pointer */
        *l = malloc();
    }
}

void *List_get(List, Filter, void *)
{
}

void List_remove(List, void *)
{
}

void List_free(List, DEPTH_E)
{
}
