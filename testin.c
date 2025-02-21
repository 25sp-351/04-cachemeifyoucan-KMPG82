#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

int main() {

    Linked_list* ll = create_linked_list();

    insert_node(1, &ll);
    insert_node(3, &ll);
    insert_node(2, &ll);
    insert_node(6, &ll);
    insert_node(4, &ll);

    printf("head next %d\n", ll->head->next->index);

    int index = evict_index(&ll);

    printf("evicted %d\n", index);

    printf("head %d\n", ll->head->index);
    printf("tail %d\n", ll->tail->index);

    index = evict_index(&ll);

    printf("evicted %d\n", index);

    index = evict_index(&ll);

    printf("evicted %d\n", index);

    printf("head %d\n", ll->head->index);

    printf("tail %d\n", ll->tail->index);

    index = evict_index(&ll);

    printf("evicted %d\n", index);

    printf("head %d\n", ll->head->index);

    printf("tail %d\n", ll->tail->index);

    index = evict_index(&ll);

    printf("evicted %d\n", index);

    printf("head %d\n", ll->head);

    printf("tail %d\n", ll->tail);

    index = evict_index(&ll);
    index = evict_index(&ll);
    index = evict_index(&ll);

    return 0;
}
