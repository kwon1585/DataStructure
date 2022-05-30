#include "maze.h"

int main(void)
{
  FILE *file_in = fopen("input.txt", "rt");
  FILE *file_out = fopen("output.txt", "wt");

  char **map = create_map(file_in);

  print_map();

  return 0;
}