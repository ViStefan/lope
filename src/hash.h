#ifndef HASH_H
#define HASH_H 1

typedef struct Hash *Hash;
// limits.h max filename?
typedef char *KEY_T;

void Hash_add(Hash *, KEY_T, void *);
void Hash_remove(Hash *, KEY_T);
void *Hash_get(Hash *, KEY_T);
void Hash_free(Hash *);

#endif /* ifndef HASH_H */
