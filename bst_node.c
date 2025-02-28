#include "bst_node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* creates a new bst node and initializes its values */
Bst_node* create_bst_node(const int* cuts, int number_of_length_options,
                          int rod_length, int max_val, int remainder) {
    Bst_node* new_node = malloc(sizeof(Bst_node));

    new_node->cuts     = malloc(number_of_length_options * sizeof(int));

    memcpy(new_node->cuts, cuts, number_of_length_options * sizeof(int));

    new_node->rod_length  = rod_length;
    new_node->max_val     = max_val;
    new_node->remainder   = remainder;
    new_node->left_child  = NULL;
    new_node->right_child = NULL;

    return new_node;
}

/* inserts bst node to the bst */
void insert_bst_node(Bst_node** root, Bst_node* node) {
    if (*root == NULL) {
        *root = node;
        return;
    }

    if (node->rod_length < (*root)->rod_length)
        insert_bst_node(&((*root)->left_child), node);
    else
        insert_bst_node(&((*root)->right_child), node);
}

/* finds a node with the respective key(rod length) */
Bst_node* find_bst_node(Bst_node* root, int rod_length) {
    if (root == NULL || root->rod_length == rod_length)
        return root;

    Bst_node* current_node = root;

    while (current_node != NULL && current_node->rod_length != rod_length)
        if (current_node->rod_length > rod_length)
            current_node = current_node->left_child;
        else
            current_node = current_node->right_child;

    return current_node;
}

/* handles deleting a node from the bst while maintaining bst properties */
void delete_bst_node(Bst_node** root, int rod_length,
                     int number_of_length_options) {
    if ((*root) == NULL)
        return;

    if (rod_length < (*root)->rod_length) {
        delete_bst_node(&((*root)->left_child), rod_length,
                        number_of_length_options);
    } else if (rod_length > (*root)->rod_length) {
        delete_bst_node(&((*root)->right_child), rod_length,
                        number_of_length_options);
    } else {
        Bst_node* temp;

        if ((*root)->left_child == NULL) {
            temp = (*root)->right_child;
            free(*root);
            *root = temp;
            return;
        }

        if ((*root)->right_child == NULL) {
            temp = (*root)->left_child;
            free(*root);
            *root = temp;
            return;
        }

        if ((*root)->left_child != NULL && (*root)->right_child != NULL) {
            temp = find_min_bst_node((*root)->right_child);

            copy_node_data(root, temp, number_of_length_options);

            delete_bst_node(&((*root)->right_child), temp->rod_length,
                            number_of_length_options);
        }
    }
}

/* finds the left most node starting from the given root */
Bst_node* find_min_bst_node(Bst_node* root) {
    if (root == NULL)
        return root;

    while (root->left_child != NULL)
        root = root->left_child;

    return root;
}

/* copies a nodes data to another node */
void copy_node_data(Bst_node** destination, Bst_node* source,
                    int number_of_length_options) {
    (*destination)->rod_length = source->rod_length;
    (*destination)->max_val    = source->max_val;
    (*destination)->remainder  = source->remainder;

    memcpy((*destination)->cuts, source->cuts,
           number_of_length_options * sizeof(int));
}

/* prints the BST values in order */
void print_bst(Bst_node* root) {
    if (root == NULL)
        return;

    print_bst(root->left_child);
    printf("%d ", root->rod_length);
    print_bst(root->right_child);
}
