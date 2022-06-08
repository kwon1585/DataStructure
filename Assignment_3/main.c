#include "bst.h"

int main(void)
{
  FILE *file_in = fopen("input.txt", "rt");
  FILE *file_out = fopen("output.txt", "wt"); 


  print_bst();

  return 0;
}