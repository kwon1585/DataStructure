#include "bst.h"

void insert_node(t_node **root, int data, FILE *file)                       //트리에 새로운 노드를 추가하는 함수
{
	t_node *parent = 0, *now = 0;                                             //삽입될 위치의 parent 노드를 가리킬 포인터와 중복 삽입 때 이용할 포인터를 선언.
	t_node *new = (t_node *)malloc(sizeof(t_node));                           //새롭게 삽입될 노드의 메모리 할당
	if (new == NULL)                                                          //메모리 할당 에러로 인한 오류 방지
		return;
	new->data = data;                                                         //새로운 노드에 data값을 넣고 다음 노드를 가리킬 포인터 초기화
	new->left = new->right = NULL;

	if (*root == NULL)                                                        //처음 삽입되는 노드일 경우 root가 가리키도록 한다.
		*root = new;
	else                                                                      //아닐경우, 
	{
		parent = find_parent(*root, data);                                      //노드가 들어갈 위치의 부모노드를 찾는다.          
		if (search_node(*root, data))                                           //중복 삽입의 경우
		{
			if (parent->left == NULL) now = parent->right;                        //값이 중복되는 노드가 부모의 왼쪽인지 오른쪽인지 찾아 now 변수에 저장한다.
			else if (parent->right == NULL) now = parent->left;                   //이 때, 부모의 왼쪽 오른쪽 중에 NULL을 가리킬 수도 있으니 바로 data에 접근하지 않고
			else
				now = (parent->left->data == data) ? parent->left : parent->right;  //하나씩 확인하여 찾는다.
			new->left = now->left;                                                //중복 노드의 왼쪽 child에 새로운 노드를 삽입한다.
			now->left = new;
		}
		else if (parent->data > data) parent->left = new;                       //중복 삽입이 아닐 경우, 부모노드의 값과 비교하여 왼쪽 또는 오른쪽에 삽입한다.
		else parent->right = new; 
	}
	print_tree(*root, file);                                                  //tree를 level-order로 출력한다.

	return;
}

int search_node(t_node *node, int data)                                     //tree에 해당 값이 있는지 preorder로 순회하여 확인하는 함수
{
	int rtn = 0;
	
	if (node == NULL) return 0;                                               //재귀함수이므로 끝까지 못찾은 경우에는 0 반환
	if (node->data == data) return 1;                                         //찾은 경우 1을 반환한다.

	rtn += search_node(node->left, data);                                     //그렇게 반환되는 값을 더하여
	rtn += search_node(node->right, data);

	return rtn;                                                               //하나라도 찾을 경우 1 이상, 트리 전체에서 못찾았을 경우에 0을 반환하게 한다.
}

int delete_node(t_node **root, int data, FILE *file)                        //트리에서 값을 찾아 해당 노드를 삭제하는 함수
{
	int tmp_data = 0;
	t_node *parent = 0, *now = 0, *tmp = 0;

	if (search_node(*root, data) == 0)                                        //해당 값이 없을 경우 Not Exist를 출력하고 함수를 종료한다.
	{
		fprintf(file, "Not Exist");
		return 0;
	}

	parent = find_parent(*root, data);                                        //함수가 종료되지 않았으므로 해당 값의 부모노드를 찾는다.
	if (parent == NULL) now = *root;                                          //NULL이 반환되었을 경우 삭제하고자 하는 노드가 root노드이다.
	else                                                                      //그 외에는 insert 때처럼 NULL의 멤버를 참조하지 않도록 유의하여 삭제할 노드를 now에 저장한다.
	{
		if (parent->left == NULL) now = parent->right;
		else if (parent->right == NULL) now = parent->left;
		else
			now = (parent->left->data == data) ? parent->left : parent->right;

	}
	
	if (now->left == NULL || now->right == NULL)                              //삭제할 노드의 좌우 포인터 중 NULL이 있을 경우
	{
		if (now->left == now->right)                                            //있을 경우 둘다 NULL인지, 즉 종단노드인지 확인하고
		{
			if (parent == NULL)                                                   //종단노드이면서 루트노드일 경우
			{
				free(now);                                                          //루트를 초기화하고 메모리 할당을 해제한다.
				*root = NULL;
			}
			else                                                                  //루트노드는 아닐경우
			{
				if (parent->left == now) parent->left = NULL;                       //좌우 노드 중 해당하는 노드를 가리키는 포인터를 초기화하고 메모리 할당 해제한다.
				else parent->right = NULL;
				free(now);
			}
		}
		else                                                                    //종단노드가 아닐경우
		{
			if (parent == NULL)                                                   //종단노드가 아니면서 루트노드일 경우
			{
				*root = (now->left != NULL) ? now->left : now->right;               //루트의 좌우 중 NULL이 아닌 노드를 루트로 하고
				free(now);                                                          //메모리 할당 해제한다.
			}
			else                                                                  //종단노드도 루트노드도 아닐 경우
			{
				if (parent->left == now)                                            //삭제할 노드의 자식노드 중 NULL이 아닌 노드를 부모노드에 연결한다.
					parent->left = (now->left != NULL) ? now->left : now->right;
				else parent->right = (now->left != NULL) ? now->left : now->right;
				free(now);
			}
		}
	}
	else                                                                      //양쪽 모두 값이 있는 노드를 삭제하려는 경우
	{
		tmp = find_parent(now->right, data);                                    //오른쪽 서브트리에서 가장 왼쪽 아래 노드를 찾아서
		tmp_data = tmp->data;
		delete_node(&now, tmp->data, file);                                     //해당 노드를 삭제하고
		now->data = tmp_data;                                                   //삭제할 값이 들어있던 노드를 유지한 채 값만 변경해준다.
	}

	return 1;                                                                 //삭제에 성공할 경우 트리를 출력하는 함수 실행을 위해 1을 반환해준다.
}

t_node *find_parent(t_node *root, int data)                                 //데이터가 들어갈 위치나 같은 값의 위치의 부모노드를 반환하는 함수.
{
	t_node *past = 0, *now = root;

	while (now)                                                               //노드와 같은 값을 찾는 과정을 반복하다가
	{
		if (now->data == data) break;                                           //같은 값이 있을경우 함수를 종료하고 부모노드를 반환
		past = now;
		if (now->data > data) now = now->left;                                  //아닐 경우 왼쪽 오른쪽 중 적합한 위치를 따라가다가 들어갈 위치의 부모노드를 반환
		else now = now->right;
	}
	return past;
}

void print_tree(t_node *root, FILE *file)                                   //트리를 Level-order로 출력하는 함수
{
	int now_level = 0;                                                        //현재 삽입하는 노드의 레벨을 담을 변수
  if (root == NULL)                                                         //비어있는 트리의 경우 별도의 큐 생성 없이 함수를 종료한다.
		return;

	q_head *header = (q_head *)malloc(sizeof(q_head));                        //Queue를 생성하고
	if (header == NULL)                                                       //메모리 할당 오류 방지
		return;
	header->head = header->tail = NULL;                                       //초기화시킨다.

	enqueue(header, root, 1);                                                 //루트노드를 큐에 넣고
	while (1)                                                                 //레벨의 모든 트리노드가 없을 때까지 반복문을 돌린다.
	{
		dequeue(header, file);                                                  //큐에서 노드를 제거할 때마다 좌우 노드를 큐에 삽입하고
		if (header->head->level != now_level)                                   //새로운 레벨을 출력 시작할 때마다 해당 레벨에 모든 노드가 비어있는 노드인지 확인한다.
		{
			if (is_empty(header))                                                 //그럴 경우 더이상 큐에 삽입 및 제거를 하지 않고
				break;
			now_level = header->head->level;
		}
		fprintf(file, ", ");
	}
	free_queue(header);                                                       //메모리를 할당 해제해준다.
	return;
}

void free_tree(t_node *root)                                                //트리를 만들기위해 할당한 메모리들을 트리를 따라가며 모두 할당 해제해주는 함수이다.
{
	if (root == NULL)
		return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}