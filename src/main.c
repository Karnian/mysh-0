#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "utils.h"

static void release_argv(int argc, char*** argv);

int main()
{
  char buf[8096];
  int argc;
  char** argv;

  while (1) {
    fgets(buf, 8096, stdin);
//	printf("parse start\n");
    mysh_parse_command(buf, &argc, &argv);
//	printf("argc : %d\n", argc);
//	printf("parse end\nargv[0] : %s\n", argv[0]);

    if (strcmp(argv[0], "") == 0) {

	printf("if no.1 excuted\n");

      goto release_and_continue;
    } else if (strcmp(argv[0], "cd") == 0) {

	printf("if no.2 excuted\n");

      if (do_cd(argc, argv)) {
        fprintf(stderr, "cd: Invalid arguments\n");
      }
    } else if (strcmp(argv[0], "pwd") == 0) {

	printf("if no.3 excuted\n");

      if (do_pwd(argc, argv)) {
        fprintf(stderr, "pwd: Invalid arguments\n");
      }
    } else if (strcmp(argv[0], "exit") == 0) {

	printf("exit excuted\n");

      goto release_and_exit;
    } else {
      fprintf(stderr, "%s: command not found\n", argv[0]);
    }
release_and_continue:
    release_argv(argc, &argv);
	printf("realse done\n");
    continue;
release_and_exit:
    release_argv(argc, &argv);
    break;
  }

  return 0;
}

static void release_argv(int argc, char*** argv) {
  for (int i = 0; i < argc; ++i) {
    free((*argv)[i]);
  }
  free(*argv);
  *argv = NULL;
}
