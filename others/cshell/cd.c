#include <stdio.h>
#include <dirent.h>

void cd(const char *cd_to)
{
  chdir(cd_to);
}

int main(int argc, char const *argv[])
{
  cd(argv[1]);
  char buff[100];
  getcwd(buff, sizeof(buff));
  printf("current the path %s\n", buff);
  return 0;
}
