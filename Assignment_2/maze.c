#include "maze.h"

point create_maze(FILE *file)
{
  int   row = 0;
  point start = {0, 0};
  char  buf[MAX] = {0, };

  while (fgets(buf, MAX, file))
  {
    for (int col = 0; buf[col] && (buf[col] != '\n'); col++)
    {
      maze[row][col] = buf[col];
      if (buf[col] == 'E')
      {
        start.row = row;
        start.col = col;
      }
    }
    row++;
  }
  return start;
}

void find_path(point now_loc)
{
  point next_loc = {0, 0};
  
  maze[now_loc.row][now_loc.col] = '2';
  push_next(now_loc);

  if (is_empty()){
    printf("실패");
    return;
  } 
  next_loc = pop();
  if (maze[next_loc.row][next_loc.col] == 'X')
  {
    printf("도착\n탐색 성공");
    return;
  }
  return find_path(next_loc);
}

void print_maze(FILE *file, int done)
{
  if (done)
    fprintf(file, "\n\n탐색 경로\n");

  for (int i = 0; maze[i][0]; i++)
  {
    for (int j = 0; maze[i][j]; j++)
    {
      switch (maze[i][j])
      {
      case '0':
        fprintf(file, "  ");
        break;
      case '1':
        fprintf(file, "[]");
        break;
      case '2':
        fprintf(file, ". ");
        break;
      default:
        fprintf(file, "%c ", maze[i][j]);
        break;
      }
    }
    
    if (maze[i+1][0])
      fprintf(file, "\n");
  }
}