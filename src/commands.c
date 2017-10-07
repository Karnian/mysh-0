#include <string.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
	char pwdname[100000];
	if(getcwd(pwdname, 100000) == NULL)
		perror("petcwd error\n");
	else
		printf("%s\n", pwdname);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
	for(int i = 0; i < argc; i++)
	{
		if(argv[i] == "|")
			return -1;
	}
  return 1;
}
