#pragma once

typedef struct Bst_node {
    int rod_length;
    int max_val;
    int* cuts;
    struct Bst_node* left_child;
    struct Bst_node* right_child;
} Bst_node;

Bst_node* create_node(const int* cuts, int number_of_options, int rod_length,
                      int max_val);
