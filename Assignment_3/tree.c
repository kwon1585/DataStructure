#include "bst.h"

void insert_node(t_node **root, int data, FILE *file)
{
    t_node *now = *root;
    t_node *new = (t_node *)malloc(sizeof(t_node));

    if (*root == NULL)
    {
        *root = new;
        return;
    }
    while (now)
    {

    }

}

void search_node(t_node *root, int data, FILE *file)
{

}

void delete_node(t_node **root, int data, FILE *file)
{

}

void print_tree(t_node *root, int data, FILE *file)
{

}

void free_tree(t_node **root)
{

}