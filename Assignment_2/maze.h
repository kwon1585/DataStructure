#ifndef MAZE_H
# define MAZE_H

# include <stdio.h>

# define MAX 100
# define MAX_STACK_SIZE 10000

typedef struct point{
    int row;
    int col;
}point;

extern char    maze[MAX][MAX];
extern point   stack[MAX_STACK_SIZE];
extern int     top;

point   create_maze(FILE *file);
void    find_path(point now_loc);
void    print_maze(FILE *file, int done);

void    push_next(point loc);
point   pop(void);
int     is_empty(void);

#endif