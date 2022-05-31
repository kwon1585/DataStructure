#include "maze.h"

int main(void)
{
  FILE *file_in = fopen("input.txt", "rt");
  //FILE *file_out = fopen("output.txt", "wt");

  char maze[MAX][MAX] = {0,};
  create_maze(file_in, maze);
  for (int i = 0; i < MAX; i++)
  {
    printf("%c ", maze[0][i]);
  }

  print_maze();

  return 0;
}