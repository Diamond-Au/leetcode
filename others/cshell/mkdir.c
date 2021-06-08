#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
   // 创建一个文件夹 赋予的权限是 777
   mkdir(argv[1], 0777);
   return 0;
}