#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *file = fopen("input.txt", "rt");	
  char line[100];
  int num = 0;

  while (fgets(line, sizeof(line), file) != NULL ) {
	  printf("%s", line);
    if (line[0] == '\n') num++;
  }

  printf("%d", num);
  return 0;
} 