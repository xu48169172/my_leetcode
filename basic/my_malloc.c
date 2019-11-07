#include <stdio.h>
#include <malloc.h>
#include <string.h>

void *my_malloc(size_t size)
{
    void *p = malloc(size);
    memset(p, 0, size);
    return p;
}
