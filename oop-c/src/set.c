#include "set.h"
#include "new.h"
#include "object.h"

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

static int heap[MANY];

void *new (const void *type, ...)
{
    // Use 0 to mark available elements of heap[], so cannot return a reference to heap[0]
    int *p;
    for (p= heap+1; p<heap+MANY;++p)
        if(!*p)
            break;
    // assert used to mark out of memory errors
    assert(p<heap+MANY);
    *p = MANY;
    return p;
}

void delete(void * _item)
{
    int *item = _item;
    if(item)
    {
        assert(item > heap && item<heap+MANY);
        *item = 0;
    }
}