#ifndef LIST_H
#define LIST_H 1

#include <stdbool.h>

typedef struct List *List;
typedef bool (*Filter)(void *, void *);
typedef enum
{
    DEEP,
    FAST
} DEPTH_E;

void List_add(List, void *);
void *List_get(List, Filter, void *);
void List_remove(List, void *);
void List_free(List, DEPTH_E);

#endif /* ifndef LIST_H */
