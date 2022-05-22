#include "polynomial.h"

void insert_node(Polyhead *poly, int coef, int exp)
{
  Polynode *new_node = (Polynode *)malloc(sizeof(Polynode));
  if (new_node == NULL)
    printf("Memory Allocation Error");
  new_node->coef = coef;
  new_node->exp = exp;
  new_node->link = NULL;

  if (poly->head == NULL)
    poly->head = poly->tail = new_node;
  else
  {
    poly->tail->link = new_node;
    poly->tail = new_node;
  }
  poly->length++;
}


void create_poly(FILE *file, Polyhead *poly1, Polyhead *poly2)
{
  int coef, exp;
  char buf[MAX] = {};

  while (fgets(buf, MAX, file)[0] != '\n')
  {
    sscanf(buf, "%d %d", &coef, &exp);
    if (coef != 0)
      insert_node(poly1, coef, exp);        
  }
  while (fgets(buf, MAX, file))
  {
    sscanf(buf, "%d %d", &coef, &exp);
    if (coef != 0)
      insert_node(poly2, coef, exp); 
  }
}


void print_poly(FILE *file, Polyhead *poly1, Polyhead *poly2)
{
  Polynode *node1 = poly1->head;
  Polynode *node2 = poly2->head;

  fprintf(file, "Addition\n");
  while(node1)
  {
    fprintf(file, "%d %d\n", node1->coef, node1->exp);
    node1 = node1->link;
  }
  fprintf(file, "Multiplication");
  while(node2)
  {
    fprintf(file, "\n%d %d", node2->coef, node2->exp);
    node2 = node2->link;
  }
}


void delete_poly()
{

}