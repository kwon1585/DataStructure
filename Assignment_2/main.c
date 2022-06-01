#include "maze.h"

int     top = 0;
char    maze[MAX][MAX] = {0, };
point   stack[MAX_STACK_SIZE] = {0, };

int main(void)
{
  FILE  *file_in = fopen("input.txt", "rt");
  FILE  *file_out = fopen("output.txt", "wt");  

  point start = create_maze(file_in);
  print_maze(file_out, 0);

  printf("시작 (%d, %d) -> ", start.row, start.col);
  find_path(start);

  print_maze(file_out, 1);

  return 0;
}