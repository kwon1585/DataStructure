#include "polynomial.h"

Polyhead add_poly(Polyhead *poly1, Polyhead *poly2)
{
  Polyhead poly_add = {0, NULL, NULL};
  Polynode *node1 = poly1->head;
  Polynode *node2 = poly2->head;

  while (node1)
  {
    insert_node(&poly_add, node1->coef, node1->exp);
    node1 = node1->link;
  }
  while (node2)
  {
    insert_node(&poly_add, node2->coef, node2->exp);
    node2 = node2->link;
  }

  poly_rearrange(&poly_add);
  poly_same_exp(&poly_add);
    
  return poly_add;
}

Polyhead mul_poly(Polyhead *poly1, Polyhead *poly2)
{
  Polyhead poly_mul = {0, NULL, NULL};
  Polynode *node1 = poly1->head;
  Polynode *node2 = poly2->head;

  while (node1)
  {
    while (node2)
    {
      insert_node(&poly_mul, (node1->coef)*(node2->coef), (node1->exp)*(node2->exp));
      node2 = node2->link;
    }
    node1 = node1->link;
    node2 = poly2->head;
  }

  poly_rearrange(&poly_mul);
  poly_same_exp(&poly_mul);

  return poly_mul;
}