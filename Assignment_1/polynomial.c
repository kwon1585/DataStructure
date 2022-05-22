#include "polynomial.h"

void insert_node(Polyhead *poly, int coef, int exp)           //poly에 새로운 node를 삽입하는 함수
{
  Polynode *new_node = (Polynode *)malloc(sizeof(Polynode));  //Polynode 구조체 크기만큼 메모리 할당
  if (new_node == NULL)                                       //Allocation 실패시,
    printf("Memory Allocation Error");                        //Error Message 출력
  new_node->coef = coef;                                      //새로운 변수에 인자로 들어온 값 대입
  new_node->exp = exp;
  new_node->link = NULL;                                      //마지막에 삽입할 node이므로 link는 NULL을 가리키도록 함

  if (poly->head == NULL)                                     //비어있는 리스트일 경우,
    poly->head = poly->tail = new_node;                       //헤더의 head, tail이 모두 새로운 node를 가리키도록 함
  else                                                        //아닐 경우,
  {
    poly->tail->link = new_node;                              //tail node가 새로운 node를 가리키게 하고 
    poly->tail = new_node;                                    //tail이 새로운 node를 가리키게 함
  }
}


void create_poly(FILE *file, Polyhead *poly1, Polyhead *poly2)  //input 파일의 내용을 읽어 들여 다항식 node들을 생성하여 연결리스트 제작
{
  int coef, exp;
  char buf[MAX] = {};                                           //헤더 파일에 선언된 MAX 크기를 가진 버퍼 선언

  while (fgets(buf, MAX, file)[0] != '\n')                      //공백인 줄이 들어올 때까지 파일의 한 줄을 문자열로 받아와서 버퍼에 저장
  {
    sscanf(buf, "%d %d", &coef, &exp);                          //버퍼에 저장된 문자열에서 정수 입력값 두 개를 가져옴
    if (coef != 0)                                              //계수가 0이 아니라면
      insert_node(poly1, coef, exp);                            //첫 번째 다항식 리스트 맨 끝에 입력값들로 새로운 node를 생성
  }
  while (fgets(buf, MAX, file))                                 //두 번째 다항식 리스트에 같은 방식으로 새로 입력되는 값들을 담은 node를 삽입
  {
    sscanf(buf, "%d %d", &coef, &exp);
    if (coef != 0)
      insert_node(poly2, coef, exp); 
  }
}


void print_poly(FILE *file, Polyhead *poly1, Polyhead *poly2) //덧셈, 곱셈이 완료된 다항식 연결리스트를 파일에 출력
{
  Polynode *node1 = poly1->head;
  Polynode *node2 = poly2->head;

  fprintf(file, "Addition\n");
  while(node1)                                                //head가 가리키는 node부터 link를 따라가며 coef, exp를 출력
  {
    fprintf(file, "%d %d\n", node1->coef, node1->exp);
    node1 = node1->link;
  }
  fprintf(file, "Multiplication");
  while(node2)                                                //head가 가리키는 node부터 link를 따라가며 coef, exp를 출력
  {
    fprintf(file, "\n%d %d", node2->coef, node2->exp);
    node2 = node2->link;
  }

  delete_poly(poly1);                                         //출력이 완료된 두 리스트는 메모리 할당 해제
  delete_poly(poly2);
}


void delete_poly(Polyhead *poly)  //다항식 연결리스트 node 메모리 할당 해제 함수
{
  Polynode *node = poly->head;
  Polynode *next;

  while (node)                    //head가 가리키는 node부터 link를 따라가며 free(node)를 수행함
  {
    next = node->link;
    free(node);
    node = next;
  }
}


void sort_poly(Polyhead *poly)        //다항식 node간 
{
  Polynode *node = poly->head;
  Polynode *comp;

  while (node)                        //head가 가리키는 node부터 link를 따라가며 
  {
    comp = node->link;                //비교할 node
    while (comp)
    {
      if (node->exp < comp->exp)      //
      {
        SWAP(node->exp, comp->exp);   //
        SWAP(node->coef, comp->coef); //
      }
      comp = comp->link;              //
    }
    node = node->link;
  }
}


void same_exp(Polyhead *poly){
  Polynode *node = poly->head;
  Polynode *next;

  while (node && node->link)
  {
    next = node->link;
    if (node->exp == next->exp)
    {
      node->coef += next->coef;
      node->link = next->link;
      free(next);
    }
    if (node->exp != node->link->exp)
      node = node->link;
  }
}