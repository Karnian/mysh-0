#include <string.h>
#include "utils.h"


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  // HELLO!!
  // commit test
	int count = 0;
	char word[1000];
	int wordidx = 0;
	for(int i = 0; i < strlen(command); i++)
	{
		word[wordidx] = command[i];

		if(command[i] == " ")
		{
			argv[count] = word;
			count++;
			wordidx = 0;
		}
	}
	argv[count] = word;
	argc = strlen(argv);
}
