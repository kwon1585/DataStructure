#include "maze.h"

int main(void)
{
  FILE *file_in = fopen("input.txt", "rt");
  FILE *file_out = fopen("output.txt", "wt");

  char maze[MAX][MAX] = {0,};
  create_maze(file_in, maze);
  

  print_maze(file_out, maze);

  return 0;
}

