#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_node.h"

#define CACHE_SIZE 5

int main() {
    int number_of_options = 3;
    int array1[]          = {1, 2, 3};
    int array2[]          = {4, 5, 6};
    int array3[]          = {7, 8, 9};
    int array4[]          = {10, 11, 12};
    int array5[]          = {13, 14, 15};

    Bst_node* root   = NULL;
    Bst_node** cache = malloc(CACHE_SIZE * sizeof(Bst_node*));
    int current_size = 0;

    Bst_node* node1  = create_node(array1, number_of_options, 10, 20);
    Bst_node* node2  = create_node(array2, number_of_options, 15, 40);
    Bst_node* node3  = create_node(array3, number_of_options, 20, 60);
    Bst_node* node4  = create_node(array4, number_of_options, 14, 80);
    Bst_node* node5  = create_node(array5, number_of_options, 17, 100);
    Bst_node* node6  = create_node(array5, number_of_options, 21, 120);
    Bst_node* node7  = create_node(array5, number_of_options, 5, 1400);

    insert_node(&root, node1);
    insert_node(&root, node2);
    insert_node(&root, node3);
    insert_node(&root, node4);
    insert_node(&root, node5);
    insert_node(&root, node6);
    insert_node(&root, node7);

    cache[current_size++] = node1;
    cache[current_size++] = node2;
    cache[current_size++] = node3;
    cache[current_size++] = node4;

    print_tree(root, number_of_options);

    delete_node(&root, 15, number_of_options);

    printf("\n\nafter deletion\n");
    print_tree(root, number_of_options);


    return 0;
}
