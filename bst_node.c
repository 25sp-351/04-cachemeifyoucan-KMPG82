#include "bst_node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Bst_node* create_bst_node(const int* cuts, int number_of_options,
                          int rod_length, int max_val, int remainder,
                          int index) {
    Bst_node* new_node = malloc(sizeof(Bst_node));

    new_node->cuts     = malloc(number_of_options * sizeof(int));

    memcpy(new_node->cuts, cuts, number_of_options * sizeof(int));

    new_node->rod_length  = rod_length;
    new_node->max_val     = max_val;
    new_node->remainder   = remainder;
    new_node->index       = index;
    new_node->left_child  = NULL;
    new_node->right_child = NULL;

    return new_node;
}

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

void delete_bst_node(Bst_node** root, int rod_length, int number_of_options) {
    Bst_node* target_node = find_bst_node(*root, rod_length);

    if (target_node == NULL)
        return;

    Bst_node* parent = find_parent_bst_node(*root, target_node);

    if (target_node->left_child == NULL && target_node->right_child == NULL) {
        if (*root == target_node)
            *root = NULL;
        else if (parent->left_child == target_node)
            parent->left_child = NULL;
        else
            parent->right_child = NULL;

        free(target_node->cuts);
        free(target_node);
    } else if (target_node->left_child != NULL &&
               target_node->right_child != NULL) {
        Bst_node* least_node = find_min_bst_node(target_node->right_child);

        copy_node_data(&target_node, least_node, number_of_options);

        delete_bst_node(&target_node->right_child, least_node->rod_length,
                        number_of_options);
    } else {
        if (parent == NULL) {
            if (target_node->left_child != NULL)
                *root = target_node->left_child;
            else
                *root = target_node->right_child;
        } else if (target_node->left_child != NULL) {
            if (parent->left_child == target_node)
                parent->left_child = target_node->left_child;
            else
                parent->right_child = target_node->left_child;
        } else if (target_node->right_child != NULL) {
            if (parent->left_child == target_node)
                parent->left_child = target_node->right_child;
            else
                parent->right_child = target_node->right_child;
        }

        free(target_node->cuts);
        free(target_node);
    }
}

Bst_node* find_parent_bst_node(Bst_node* root, Bst_node* target_node) {
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

Bst_node* find_min_bst_node(Bst_node* root) {
    if (root == NULL)
        return root;

    while (root->left_child != NULL)
        root = root->left_child;

    return root;
}

void copy_node_data(Bst_node** destination, Bst_node* source,
                    int number_of_options) {
    (*destination)->rod_length = source->rod_length;
    (*destination)->max_val    = source->max_val;
    (*destination)->remainder  = source->remainder;
    (*destination)->index      = source->index;

    memcpy((*destination)->cuts, source->cuts, number_of_options * sizeof(int));
}
