#include <string.h>
#include "utils.h"


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  // HELLO!!
  // commit test

	printf("command : %s\n", command);
	printf("test1 : %c\n", command[0]);

	int count = 0;
	char word[1000];
	int wordidx = 0;
	printf("strlen(command) : %d\n", strlen(command));
	for(int i = 0; i < strlen(command); i++)
		printf("%c ", command[i]);
	printf("\n");

	for(int i = 0; i < strlen(command); i++)
	{
		word[wordidx] = command[i];
		wordidx++;
		if(command[i] == " ")
		{
			strcpy(argv[count], word);
			count++;
			wordidx = 0;
		}
	}
	printf("word is : ");
	for(int i = 0; i < strlen(word); i++)
		printf("%c ", word[i]);
	printf("\n");

	argv[count] = word;
	argv[count + 1] = "\0";
	argc = strlen(argv);

	printf("argc : %d\n", argc);
	printf("test s : %s\n", *argv);
	printf("test s complete\n");
	for(int i = 0; i < argc; i++)
	{
		printf("s : %s\n", argv[i]);
		printf("c : %c\n", *argv[i]);
		printf("word num : %d\n", strlen(argv[i]));
		for(int j = 0; j < strlen(argv[i]); j++)
		{
			printf("%c ", argv[i][j]);
		}
		printf("\n");
	}
}
