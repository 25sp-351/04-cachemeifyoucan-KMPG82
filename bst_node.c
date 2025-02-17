#include "bst_node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Bst_node {
//     int rod_length;
//     int max_val;
//     int* cuts;
//     struct Bst_node* left_child;
//     struct Bst_node* right_child;
// } Bst_node;

Bst_node* create_node(const int* cuts, int number_of_options, int rod_length,
                      int max_val) {
    Bst_node* new_node = malloc(sizeof(Bst_node));

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

void insert_node(Bst_node** root, Bst_node* node) {
    if (*root == NULL) {
        *root = node;
        return;
    }

    if (node->rod_length < (*root)->rod_length)
        insert_node(&((*root)->left_child), node);
    else
        insert_node(&((*root)->right_child), node);
}

void print_tree(Bst_node* root, int number_of_options) {
    if (root == NULL)
        return;

    printf("Rod Length: %d\nMax Value: %d\n", root->rod_length, root->max_val);
    printf("Cuts: ");
    for (int i = 0; i < number_of_options; i++)
        if (root->cuts[i] != 0)
            printf("%d ", root->cuts[i]);
    printf("\n");

    print_tree(root->left_child, number_of_options);

    print_tree(root->right_child, number_of_options);
}

Bst_node* find_node(Bst_node* root, int rod_length) {
    if (root == NULL || root->rod_length == rod_length)
        return root;

    if (rod_length < root->rod_length)
        return find_node(root->left_child, rod_length);

    return find_node(root->right_child, rod_length);
}

void delete_node(Bst_node** root, int rod_length) {
    Bst_node* target_node = find_node(*root, rod_length);
    if (target_node == NULL)
        return;

    // Case 1: No children
    if (target_node->left_child == NULL && target_node->right_child == NULL) {
        if (*root == target_node) {
            *root = NULL;
        } else {
            Bst_node* parent = find_parent_node(*root, target_node);

            if (parent->left_child == target_node)
                parent->left_child = NULL;
            else
                parent->right_child = NULL;
        }

        free(target_node->cuts);
        free(target_node);
    }
}

Bst_node* find_parent_node(Bst_node* root, Bst_node* target_node) {
    if (root == target_node)
        return NULL;

    Bst_node* parent = root;

    while (parent->left_child != target_node &&
           parent->right_child != target_node) {
        if (parent->rod_length > target_node->rod_length)
            parent = parent->left_child;
        else
            parent = parent->right_child;
    }

    return parent;
}
