#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  *argv = (char**)malloc(sizeof(char*)*16);
  *argc = 0;
  char* buf = strdup(command);

  char* temp = strtok(buf, " \n\t");

  if(temp != NULL && strcmp(temp, "alias") == 0){
     *argc = 0;
     (*argv)[*argc] = (char*)malloc(sizeof(char)*16);
     strcpy((*argv)[*argc], temp);
     
     (*argc)++;
     
     temp = strtok(NULL, "\n");
     (*argv)[*argc] = (char*)malloc(sizeof(char)*16);
     strcpy((*argv)[*argc], temp);

     (*argc)++;
  }
  else{
 
     while(temp != NULL)
     {
        (*argv)[*argc] = (char*)malloc(sizeof(char)*16);
        (*argv)[*argc] = strdup(temp);
        (*argc)++;
        temp = strtok(NULL, " \n\t");
     }
  }

  if((*argc) == 0)
  {
     (*argv)[*argc] = strdup("");
     (*argc)++;

  }
}
