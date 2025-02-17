#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bst_node {
    int rod_length;
    int max_val;
    int* cuts;
    struct Bst_node* left_child;
    struct Bst_node* right_child;
} Bst_node;

Bst_node* create_node(const int* cuts, int number_of_options, int rod_length,
                      int max_val) {
    Bst_node* new_node = (Bst_node*)malloc(sizeof(Bst_node));

    new_node->cuts     = malloc(number_of_options *
                                sizeof(int));  // Allocate memory for the array

    memcpy(new_node->cuts, cuts,
           number_of_options * sizeof(int));  // Copy the contents

    new_node->rod_length  = rod_length;
    new_node->max_val     = max_val;
    new_node->left_child  = NULL;
    new_node->right_child = NULL;

    return new_node;
}
