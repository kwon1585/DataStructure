#ifndef POLYNOMIAL_H
# define POLYNOMIAL_H

# include <stdio.h>
# include <stdlib.h>

# define MAX 200

typedef struct PolynomialNode{
  int       coef;
  int       exp;
  Polynode  *link;
}Polynode;

typedef struct PolynomialHeader{
  int       length;
  Polynode  *head;
  Polynode  *tail;
}Polyhead;

Polyhead add_poly();
Polyhead mul_poly();

#endif