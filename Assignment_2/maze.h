#ifndef MAZE_H
# define MAZE_H

# include <stdio.h>

# define MAX 100

void create_maze(FILE *file, char (*maze)[MAX]);
void print_maze();

#endif