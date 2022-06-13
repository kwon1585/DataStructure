#include "bst.h"

void enqueue(q_head *header, t_node *tree_node, int level)
{
	q_node *new_node = (q_node *)malloc(sizeof(q_node));
	if(new_node == NULL)
		return;
	new_node->level = level;
	new_node->tree_node = tree_node;
	new_node->next = NULL;
	
	if (header->head == NULL)
		header->head = header->tail = new_node;
	else
	{
		header->tail->next = new_node;
		header->tail = new_node;
	}
	return;
}

void dequeue(q_head *header, FILE *file)
{
	q_node *delete_node = header->head;

	if (delete_node == NULL)
		return;

	if (delete_node->tree_node == NULL)
	{
		fprintf(file, "0");
		enqueue(header, NULL, (delete_node->level)+1);
		enqueue(header, NULL, (delete_node->level)+1);
	}
	else
	{
		fprintf(file, "%d", delete_node->tree_node->data);
		enqueue(header, delete_node->tree_node->left, (delete_node->level)+1);
		enqueue(header, delete_node->tree_node->right, (delete_node->level)+1);
	}

	header->head = delete_node->next;
	free(delete_node);

	return;
}

int is_empty(q_head *header)
{
	q_node *now_node = header->head;

	while (now_node != NULL)
	{
		if (now_node->tree_node != NULL)
			return 0;
		now_node = now_node->next;
	}
	return 1;
}

void free_queue(q_head *header)
{
	q_node *now_node = header->head;

	while (now_node != NULL)
	{
		now_node = now_node->next;
		free(now_node);
	}
	free(header);
	return;
}

