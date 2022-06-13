#include "bst.h"

void enqueue(q_head *header, t_node *tree_node, int level)                      //enqueue
{
	q_node *new_node = (q_node *)malloc(sizeof(q_node));                          //새로운 큐노드 생성
	if(new_node == NULL)                                                          //메모리 할당 오류 방지
		return;
	new_node->level = level;                                                      //큐노드 초기화
	new_node->tree_node = tree_node;
	new_node->next = NULL;
	
	if (header->head == NULL)                                                     //첫 노드일 경우 헤드와 테일이 모두 가리키도록 설정
		header->head = header->tail = new_node;
	else                                                                          //아닐 경우 마지막 노드 끝에 연결 후 테일이 새로운 노드를 가리키도록 설정
	{
		header->tail->next = new_node;
		header->tail = new_node;
	}
	return;
}

void dequeue(q_head *header, FILE *file)                                        //dequeue
{
	q_node *delete_node = header->head;                                           //헤드가 가리키는 노드를 제거

	if (delete_node == NULL)
		return;

	if (delete_node->tree_node == NULL)                                           //제거하면서 멤버인 트리노드의 포인터가 가리키는 노드의 좌우 노드를 큐에 삽입하는데
	{                                                                             //비어있는 노드, 즉 NULL을 가리킬 경우 0을 출력하고 빈 노드를 계속 집어넣는다.
		fprintf(file, "0");
		enqueue(header, NULL, (delete_node->level)+1);
		enqueue(header, NULL, (delete_node->level)+1);
	}
	else                                                                          //비어있지 않은 노드 역시 NULL이 아닌 노드들을 같은 방식으로 넣어준다.
	{
		fprintf(file, "%d", delete_node->tree_node->data);
		enqueue(header, delete_node->tree_node->left, (delete_node->level)+1);
		enqueue(header, delete_node->tree_node->right, (delete_node->level)+1);
	}

	header->head = delete_node->next;                                             //헤드노드를 옮기고
	free(delete_node);                                                            //메모리 할당을 해제한다.

	return;
}

int is_empty(q_head *header)                                                    //큐가 비어있는지 확인하는 함수로 정확히는 비어있는 것이 아니라
{
	q_node *now_node = header->head;                                              //들어가있는 같은 레벨의 노드들이 모두 NULL값인지 확인하여 출력을 중단할지 판단하는 함수이다.

	while (now_node != NULL)
	{
		if (now_node->tree_node != NULL)                                            //하나라도 NULL이 아닐 경우 0을 반환하여 출력이 계속되도록 한다.
			return 0;
		now_node = now_node->next;
	}
	return 1;
}

void free_queue(q_head *header)                                                 //큐의 노드들을 따라가며 메모리할당 해제하는 함수이다.
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