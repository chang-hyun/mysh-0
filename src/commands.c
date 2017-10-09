#include <string.h>
#include <unistd.h>
#include <stdio.h>
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
  char dir[1000];
  getcwd(dir, 1000);
  printf("%s\n", dir);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  
  if(strcmp(argv[0], "cd")!=0 || argc != 2)
  {
    return 0;
  }
  else if(chdir(argv[argc-1])<0) return 0;
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  char dir[1000];
  if(strcmp(argv[0], "pwd")!=0 || argc >= 2)
  {
    return 0;
  }
  return 1;
}
