#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  // HELLO!!
  // commit test
//	printf("command : %s\n", command);
//	argc = (int*)malloc(sizeof(int));
//	printf("malloc 1 done\n");
	*argv = (char**)malloc(sizeof(char*) * 8096);
	if(!strlen(command))
	{
		(*argv)[0] = (char*)malloc(sizeof(char));
		strcpy((*argv)[0], "");
		*argc = 1;
		return;
	}
//	for(int i = 0; i < 8096; i++)
//	{
//		(*argv)[i] = (char*)malloc(sizeof(char) * 8096);
//	}
	
//	printf("malloc done\n");
	int count = 0;
//	char word[8096];
	char* word = (char*)malloc(sizeof(char*) * 8096);
//	char psword[8096][8096];
//	char chk[10] = {' ', '\n', '\t', '\0'};
	int wordidx = 0;
	
//	printf("for string start\n");
//	printf("%d\n", strlen(command));
	for(int i = 0; i < strlen(command); i++)
	{
//		printf("i : %d\n", i);
		if(command[i] == ' ' || command[i] == '\n'
 		|| command[i] == '\t' || command[i] == '\0')
		{
			sscanf((command + wordidx), "%s", word);
//			printf("chk if\n");
//			printf("word : %s\n", word);
			(*argv)[count] = (char*)malloc(sizeof(char) * (strlen(word) + 1));
			strcpy((*argv)[count], word); 
			count++;
			wordidx += strlen(word);
//			printf("argv[%d] : %s\nnum : %d\n", count - 1, argv + count - 1, strlen((argv + count)));
//			strcpy(word, "\0");
		}
		else
		{
//			word[wordidx] = *(command + i);
			wordidx++;
		}
//		printf("if end\n");
	}
	*argc = count;
	free(word);
	*argv = (char**)realloc(*argv, sizeof(char*) * (*argc));
//	for(int i = 0; i < count; i++)
//		strcpy(**argv, pw[i]);
//	printf("argv[0] : %s\n", argv[0]);
//	printf("for string end\n");
//	for(int i = 0; i < strlen(psword); i++)
//	{
//		printf("%s\n", psword[i]);
//	}
//	printf("argc : %d\n", argc);
//	printf("test s : %s\n", *argv);
//	printf("test s complete\n");
//	for(int i = 0; i < argc; i++)
//	{
//		printf("s : %s\n", argv[i]);
//		printf("c : %c\n", argv[i][2]);
//	}
}
