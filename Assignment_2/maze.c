#include "maze.h"

void create_maze(FILE *file, char (*maze)[MAX])
{
  int row = 0;
  char buf[MAX] = {0, };

  while (fgets(buf, MAX, file))
  {
    for (int col = 0; buf[col] != '\n'; col++)
      maze[row][col] = buf[col];
    row++;
  }
}

void print_maze(FILE *file, char (*maze)[MAX])
{
  file = 0;
  for (int i = 0; i<10; i++)
  {
    for (int j = 0; j<10; j++)
      printf("%c", maze[i][j]);
    printf("\n");
  }
}