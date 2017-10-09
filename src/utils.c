#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
   char buf[8096];
   char key[4] = " \n\t";
   char *p;

   /* parse buff for counting the number of arguments */
   strcpy(buf, command);
   int l = strlen(buf);
   for (int i = 0; i < l; i++) {
      if (buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\t') {
         buf[i] = 0;
      }
   }
   int flag = 0;
   int tokcnt = 0;
   for (int i = 0; i < l; i++) {
      if (buf[i] != 0 && !flag) {
         tokcnt++;
         flag = 1;
      }
      if (buf[i] == 0) flag = 0;
   }
   
   if(tokcnt == 0)
      *argv = (char**)malloc(sizeof(char*));
   else
      *argv = (char**)malloc(tokcnt*sizeof(char*));
   
   strcpy(buf, command);
   if(tokcnt == 0 && buf[0] != 0) {
      (*argv)[0] = (char*)malloc(sizeof(char));
      strcpy((*argv)[0], "");
      (*argc) = 1;
      return;
   }
   (*argc) = 0;
   p = strtok(buf, key);
   
   while (p != NULL) {
      (*argv)[*argc] = (char*)malloc(strlen(p) * sizeof(char)+1);
      strcpy((*argv)[*argc], p);
      p = strtok(NULL, key);
      (*argc)++;   
   }
}
