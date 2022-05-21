#include "polynomial.h"

int main(void)
{
  FILE *file_in = fopen("input.txt", "rt");
  FILE *file_out = fopen("output.txt", "wt");

  Polyhead poly1 = {0, NULL, NULL};
  Polyhead poly2 = {0, NULL, NULL};
  create_poly(file_in, &poly1, &poly2);

  Polyhead poly_add = add_poly(&poly1, &poly2);
  Polyhead poly_mul = mul_poly(&poly1, &poly2);

  print_poly(file_out, &poly_add, &poly_mul);
  delete_poly(&poly1, &poly2);

  fclose(file_in);
  fclose(file_out);

  return 0;
}