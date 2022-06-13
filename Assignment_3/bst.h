#ifndef BST_H
# define BST_H

//입출력(fgets, fprintf 등)을 사용하기 위한 헤더 stdio.h, 메모리 할당 및 해제(malloc, free 등)을 사용하기 위한 헤더 stdlib.h 
# include <stdio.h>
# include <stdlib.h>

//한 줄에 입력받을 최대 길이, 정수형 변수의 길이가 최대 10자리이므로 15로 여유있게 설정함.
# define MAX 15

//트리를 구성할 Node와 level-order출력을 위한 큐의 노드, 헤더를 구조체로 정의함
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

//함수 Prototype 선언
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