#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bst_node.h"

#define CACHE_SIZE 5

int main() {
    int array1[]     = {1, 2, 3};
    int array2[]    = {4, 5, 6};

    int number_of_options = 3;

    int current_size      = 0;

    Bst_node* myNode      = create_node(array1, number_of_options, 10, 20);
    Bst_node* myNode2    = create_node(array2, number_of_options, 15, 30);

    myNode->right_child  = myNode2;

    Bst_node** cache = malloc(CACHE_SIZE * sizeof(Bst_node*));

    cache[current_size++] = myNode;
    cache[current_size++] = myNode2;

    for (int i = 0; i < current_size; i++) {
        printf("Node %d:\n", i);
        printf("Rod length: %d\n", cache[i]->rod_length);
        printf("Max value: %d\n", cache[i]->max_val);
        printf("Cuts: ");
        for (int j = 0; j < number_of_options; j++) {
            printf("%d ", cache[i]->cuts[j]);
        }
        printf("\n");
    }
    // printf("Right child rod length: %d\n", myNode->right_child->rod_length);
    // printf("Right child max value: %d\n", myNode->right_child->max_val);
    // for (int i = 0; i < number_of_options; i++)
    //     printf("Right child cuts[%d] = %d\n", i, myNode->right_child->cuts[i]);

    return 0;
}
