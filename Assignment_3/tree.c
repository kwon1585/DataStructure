#include "bst.h"

void insert_node(t_node **root, int data, FILE *file)
{
	t_node *parent = 0;
	t_node *new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return;
	new->data = data;
	new->left = new->right = NULL;

	if (*root == NULL)
		*root = new;
	else
	{
		parent = find_parent(*root, data);
		if (parent->data == data)
		{
			new->left = parent->left;
			parent->left = new;
		}
		else if (parent->data > data) parent->left = new;
		else parent->right = new;
	}
	print_tree(*root, file);

	return;
}

int search_node(t_node *node, int data)
{
	int rtn = 0;
	
	if (node == NULL) return 0;
	if (node->data == data) return 1;

	rtn += search_node(node->left, data);
	rtn += search_node(node->right, data);

	return rtn;
}

int delete_node(t_node **root, int data, FILE *file)
{
	int tmp_data = 0;
	t_node *parent = 0, *now = 0, *tmp = 0;

	if (search_node(*root, data) == 0)
	{
		fprintf(file, "Not Exist");
		return 0;
	}

	parent = find_parent(*root, data);
	if (parent == NULL) now = *root;
	else 
		now = (parent->left->data == data) ? parent->left : parent->right;

	if (now->left == NULL || now->right == NULL)
	{
		if (now->left == now->right)
		{
			if (parent == NULL)
			{
				free(now);
				*root = NULL;
			}
			else
			{
				if (parent->left == now) parent->left = NULL;
				else parent->right = NULL;
				free(now);
			}
		}
		else
		{
			if (parent == NULL)
			{
				*root = (now->left != NULL) ? now->left : now->right;
				free(now);
			}
			else
			{
				if (parent->left == now)
					parent->left = (now->left != NULL) ? now->left : now->right;
				else parent->right = (now->left != NULL) ? now->left : now->right;
				free(now);
			}
		}
	}
	else
	{
		tmp = find_parent(now->right, data);
		tmp_data = tmp->data;
		delete_node(&now, tmp->data, file);
		now->data = tmp_data;
	}

	return 1;
}

t_node *find_parent(t_node *root, int data)
{
	t_node *past = 0, *now = root;

	while (now)
	{
		if (now->data == data) break;
		past = now;
		if (now->data > data) now = now->left;
		else now = now->right;
	}
	return past;
}

void print_tree(t_node *root, FILE *file)
{
	int now_level = 0;
	q_head *header = (q_head *)malloc(sizeof(q_head));
	if (header == NULL)
		return;
	header->head = header->tail = NULL;

	if (root == NULL)
		return;

	enqueue(header, root, 1);
	while (1)
	{
		dequeue(header, file);
		if (header->head->level != now_level)
		{
			if (is_empty(header))
				break;
			now_level = header->head->level;
		}
		fprintf(file, ", ");
	}
	free_queue(header);
	
	return;
}

void free_tree(t_node *root)
{
	if (root == NULL)
		return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}