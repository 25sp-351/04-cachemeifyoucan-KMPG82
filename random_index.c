#include <bsd/stdlib.h>
#include <stdio.h>

/* takes in cache size as the upper bound, then returns a random integer to
   evict */
int evict_index(int cache_size) {
    int index_to_evict = arc4random_uniform(cache_size);

    return index_to_evict;
}
