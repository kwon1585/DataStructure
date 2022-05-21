#include <stdio.h>
#include <stdlib.h>

typedef struct PolynomialNode{
  int coef;
  int exp;
  struct PolynomialNode *link;
}Polynode;

typedef struct PolynomialHeader{
  int length;
  Polynode *head;
}Polyhead;
