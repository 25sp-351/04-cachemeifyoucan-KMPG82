#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_node.h"

#define CACHE_SIZE 5

int main() {
    int number_of_options = 3;
    int array1[]          = {0, 3, 0};
    int array2[]          = {4, 5, 6};
    Bst_node* root        = NULL;
    Bst_node** cache      = malloc(CACHE_SIZE * sizeof(Bst_node*));
    int current_size      = 0;

    Bst_node* node1       = create_node(array1, number_of_options, 10, 20);
    Bst_node* node2       = create_node(array2, number_of_options, 15, 450);

    insert_node(&root, node1);
    insert_node(&root, node2);

    cache[current_size++] = node1;
    cache[current_size++] = node2;

    print_tree(root, number_of_options);

    delete_node(&root, 15);
    printf("\n");

    print_tree(root, number_of_options);
    printf("\n");

    delete_node(&root, 10);

    printf("after deleting everything\n");
    print_tree(root, number_of_options);

    // Bst_node* parent = find_parent_node(root, node2);
    //  if(parent !=NULL)
    //      printf("Parent rod length: %d\n", parent->rod_length);

    // print_tree(root, number_of_options);

    // Bst_node* needed_node = find_node(root, 10);

    // if (needed_node != NULL) {
    //     printf("needed node rod length: %d\n", needed_node->rod_length);
    //     printf("needed node max val: %d\n", needed_node->max_val);
    // }

    // printf("root: %d\n", root->rod_length);
    // for (int i = 0; i < number_of_options; i++)
    //     printf("root cuts: %d\n", root->cuts[i]);

    return 0;
}
