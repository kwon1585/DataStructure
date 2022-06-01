#include "maze.h"

void push(int row, int col)
{
	point tmp;

	tmp.row = row;
	tmp.col = col;
	stack[top++] = tmp;
}

void push_next(point loc)
{
	if (loc.row > 0)
		if (maze[loc.row - 1][loc.col] == '0' || maze[loc.row - 1][loc.col] == 'X')
			push(loc.row - 1, loc.col);
	if (loc.col > 0)
		if (maze[loc.row][loc.col - 1] == '0' || maze[loc.row][loc.col - 1] == 'X')
			push(loc.row, loc.col - 1);
	
	if (maze[loc.row + 1][loc.col] == '0' || maze[loc.row + 1][loc.col] == 'X')
		push(loc.row + 1, loc.col);
	if (maze[loc.row][loc.col + 1] == '0' || maze[loc.row][loc.col + 1] == 'X')
		push(loc.row, loc.col + 1);
}

point pop(void)
{
	point rtn;
	do
	{
		if (top == 0)
			break;
		rtn = stack[--top];
	} while (maze[rtn.row][rtn.col] == '2');

	printf("(%d, %d) -> ", rtn.row, rtn.col);
	return rtn;
}

int is_empty(void)
{
  if (top <= 0)
    return 1;
	return 0;
}