#include <stdio.h>
int main(int argc, char *argv[])
{
  // 通过argv 字符串数组来进行输入参数的判定
  int i;
  for (i = 1; i < argc; i++)
  {
    printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
  }
  printf("\n");
  return 0;
}