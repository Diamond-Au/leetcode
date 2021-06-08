#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
   // 使用getcwd函数获取当前当前的路径
   char pwd[100];
   getcwd(pwd, sizeof(pwd));
   printf("%s\n", pwd);
}