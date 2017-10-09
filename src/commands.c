#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
	chdir(argv + 1);
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
	char pwdname[100000];
	getcwd(pwdname, 100000);
	printf("%s\n", pwdname);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
	DIR *dp;
	struct dirent *dirp;
	dp = opendir(".");
	
	while(dirp = readdir(dp))
	{
		if(!strcmp(dirp->d_name, argv + 1))
			return 1;
	}
  return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
	for(int i = 0; i < argc; i++)
	{
		if(!strcmp(argv[i], "|"))
			return 0;
	}
  return 1;
}
