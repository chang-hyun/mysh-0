#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  *argc = 0;
  
  char cmd[100];
  char restraints[] = " \t\n";
  strcpy(cmd, command);
  
  char* result;
  result = strtok(cmd, restraints);

  if(result != NULL)
  {
    
    *argv = (char**)malloc(100 * sizeof(char*));
    (*argv)[*argc] = (char*)malloc((strlen(result)) * sizeof(char));
    strcpy((*argv)[*argc], result);
    (*argc)++;
  }

  else
  {
    *argv = (char**)malloc(sizeof(char*));
    *argv[0] = (char*)malloc(sizeof(char));
    strcpy((*argv)[0], "");
    (*argc) = 1;
  }  

  while (result != NULL)
  {
    result = strtok(NULL, restraints);
    if(result != NULL)
    {
    (*argv)[*argc] = (char*)malloc((strlen(result))*sizeof(char));
    strcpy((*argv)[*argc], result);
    (*argc)++;
    }
  }
}
