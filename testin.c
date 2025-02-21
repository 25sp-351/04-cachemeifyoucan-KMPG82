#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "random_index.h"

int main() {

    int cache_size = 5;

    for (int i = 0; i < 10; i++)
        printf("%d\n", evict_index(cache_size));

    return 0;
}
