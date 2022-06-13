#include "bst.h"

int main(void)
{
  FILE   *file_in = fopen("input.txt", "rt");
  FILE   *file_out = fopen("output.txt", "wt"); 

  int     data = 0, rtn = 0;
  char    command = 0;
  char    buf[MAX] = {0, };
  t_node  *root = NULL; 

  while (fgets(buf, MAX, file_in))
  {
    if (command != 0)
      fprintf(file_out, "\n");
    sscanf(buf, "%c%d", &command, &data);
    fprintf(file_out, "%c%d : ", command, data);
    
    if (command == 'i')
      insert_node(&root, data, file_out);
    else if (command == 's')
    {
      rtn = search_node(root, data);
      rtn ? fprintf(file_out, "Exist") : fprintf(file_out, "Not Exist");
    }
    else if (command == 'd')
    {
      if (delete_node(&root, data, file_out) == 1)
        print_tree(root, file_out);
    }
    else
      fprintf(file_out, "WRONG COMMAND");
    
    for (int i = 0; i < MAX; i++)
      buf[i] = 0;
  }

  free_tree(root);
  return 0;
}