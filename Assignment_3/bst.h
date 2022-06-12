#ifndef BST_H
# define BST_H

# include <stdio.h>
# include <stdlib.h>

# define MAX 15

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}t_node;

void insert_node(t_node **root, int data, FILE *file);
void search_node(t_node *root, int data, FILE *file);
void delete_node(t_node **root, int data, FILE *file);
void print_tree(t_node *root, int data, FILE *file);

#endif