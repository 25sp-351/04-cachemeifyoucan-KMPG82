#include <bsd/stdlib.h>
#include <stdio.h>

int evict_index(int cache_size) {
    int index_to_evict = arc4random_uniform(cache_size);

    return index_to_evict;
}
