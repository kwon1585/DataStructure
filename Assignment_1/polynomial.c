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

Polyhead add_poly(){
  Polyhead poly_add;

  return poly_add;
}

Polyhead mul_poly(){
  Polyhead poly_mul;

  return poly_mul;
}



int main(void){
  FILE *file_in = fopen("input.txt", "rt");
  FILE *file_out = fopen("output.txt", "wt");

  Polyhead poly1, poly2;
  create_poly(file_in, &poly1, &poly2);

  Polyhead poly_add = add_poly(&poly1, &poly2);
  Polyhead poly_mul = mul_poly(&poly1, &poly2);

  print_poly(&poly_add, &poly_mul);
  delete_poly(&poly1, &poly2);

  fclose(file_in);
  fclose(file_out);

  return 0;
}



// input -> 파일 오류 찾기 NULL값이면 fopen 실패
// poly_list 생성 -> 다항식 오류 찾기

// 문제 없으면 합 곱

// 출력
