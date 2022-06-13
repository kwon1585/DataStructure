#ifndef BST_H
# define BST_H

# include <stdio.h>
# include <stdlib.h>

# define MAX 15

typedef struct TreeNode{
	int 						data;
	struct TreeNode *left;
	struct TreeNode	*right;
}t_node;

typedef struct QueueNode{
	int								level;
	t_node 						*tree_node;
	struct QueueNode 	*next;
}q_node;

typedef struct QueueHeader{
	q_node *head;
	q_node *tail;
}q_head;

void 		insert_node(t_node **root, int data, FILE *file);
int  		search_node(t_node *root, int data);
int 		delete_node(t_node **root, int data, FILE *file);
t_node	*find_parent(t_node *root, int data);
void 		print_tree(t_node *root, FILE *file);
void 		free_tree(t_node *root);

void 		enqueue(q_head *header, t_node *tree_node, int level);
void		dequeue(q_head *header, FILE *file);
int	 		is_empty(q_head *header);
void 		free_queue(q_head *header);

#endif