#include "bst.h"

int main(void)
{
  FILE   *file_in = fopen("input.txt", "rt");
  FILE   *file_out = fopen("output.txt", "wt"); 

  int     data = 0;
  char    command = 0;
  char    buf[MAX] = {0, };
  t_node  *root = NULL; 

  while (fgets(buf, MAX, file_in))
  {
    sscanf(buf, "%c%d", &command, &data);
    fprintf(file_out, "%s : ", buf);
    
    if (command == 'i')
      insert_node(&root, data, file_out);
    else if (command == 's')
      search_node(root, data, file_out);
    else if (command == 'd')
      delete_node(&root, data, file_out);
    else
      fprintf(file_out, "WRONG COMMAND\n");
    
    for (int i = 0; i < MAX; i++)
      buf[i] = 0;
  }

  free_tree(&root);
  return 0;
}