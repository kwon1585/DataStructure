#ifndef POLYNOMIAL_H
# define POLYNOMIAL_H

# include <stdio.h>
# include <stdlib.h>

# define MAX 200

typedef struct PolynomialNode{
  int                     coef;
  int                     exp;
  struct PolynomialNode   *link;
}Polynode;

typedef struct PolynomialHeader{
  int       length;
  Polynode  *head;
  Polynode  *tail;
}Polyhead;

void insert_node(Polyhead *poly, int coef, int exp);
void create_poly(FILE *file, Polyhead *poly1, Polyhead *poly2);
void print_poly(FILE *file, Polyhead *poly1, Polyhead *poly2);
void delete_poly();

Polyhead add_poly(Polyhead *poly1, Polyhead *poly2);
Polyhead mul_poly(Polyhead *poly1, Polyhead *poly2);

#endif