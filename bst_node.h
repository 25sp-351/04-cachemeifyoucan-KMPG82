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

void insert_node(Bst_node** root, Bst_node* node);

void print_tree(Bst_node* root, int number_of_options);

Bst_node* find_node(Bst_node* root, int rod_length);

void delete_node(Bst_node** root, int rod_length, int number_of_options);

Bst_node* find_parent_node(Bst_node* root, Bst_node* target_node);

Bst_node* find_min_node(Bst_node* root);

void copy_node_data(Bst_node** destination, Bst_node* source,
                    int number_of_options);
