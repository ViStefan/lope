#include "list.h"
#include <stdlib.h>

struct List
{
    void *v;
    List next;
};

void List_add(List *l, void *i)
{
    if (!l)
    {
        *l = malloc(sizeof(struct List));
        (*l)->next = NULL;
        (*l)->v = i;
    }
    else
    {
        List c = *l;
        while (c->next) c = c->next;
        c->next = malloc(sizeof(struct List));
        c->next->next = NULL;
        c->next->next = i;
    }
}

void *List_get(List *l, Filter f, void *i)
{
    List c = *l;

    while(c)
    {
        if (f(i, c)) return c->v;
        c = c->next;
    }

    return NULL;
}

void List_remove(List *l, void *i)
{
    List p = NULL;
    List c = *l;
    while (c)
    {
        if (c == i)
        {
            if (p)
            {
                p->next = c->next;
                free(c);
            }
            else
            {
                free(*l);
                *l = c->next;
            }
        }
        
        p = c;
        c = c->next;
    };

    *l = NULL;
}

void List_free(List *l, DEPTH_E d)
{
    List p;
    List c = *l;

    while(c) {
        p = c;
        c = c->next;
        if (d == DEEP)
            free(p->v);
        free(p);
    }

    *l = NULL;
}
