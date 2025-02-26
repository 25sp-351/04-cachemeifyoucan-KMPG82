#pragma once

typedef struct Bst_node {
    int rod_length;
    int max_val;
    int remainder;
    int* cuts;
    struct Bst_node* left_child;
    struct Bst_node* right_child;
} Bst_node;

Bst_node* create_bst_node(const int* cuts, int number_of_length_options,
                          int rod_length, int max_val, int remainder);

void insert_bst_node(Bst_node** root, Bst_node* node);

Bst_node* find_bst_node(Bst_node* root, int rod_length);

void delete_bst_node(Bst_node** root, int rod_length,
                     int number_of_length_options);

Bst_node* find_min_bst_node(Bst_node* root);

void copy_node_data(Bst_node** destination, Bst_node* source,
                    int number_of_length_options);

void print_bst(Bst_node* root);
