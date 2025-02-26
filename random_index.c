#include <bsd/stdlib.h>
#include <stdio.h>

/* returns a random integer, which will be the index to evict */
int evict_index(int cache_size) {
    int index_to_evict = arc4random_uniform(cache_size);

    return index_to_evict;
}
