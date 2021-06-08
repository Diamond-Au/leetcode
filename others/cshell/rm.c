#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
/**
 * 使用 remove函数来进行普通文件的删除
 * */
int main(int argc, char *argv[])
{
  // 没有输入足够的参数 进行提示
  if (argc < 2)
  {
    // 编译出来的执行文件名叫myRm
    printf("require one params, input `myRm -h` for help \n");
    return 0;
  }
  else
  {
    // 根据不同的选项进行提示
    if (strcmp(argv[1], "-h") == 0)
    {
      printf("myRm -V                 output the version number\n");
      printf("myRm filename           remove the file you input\n");
      return 0;
    }
    else if (strcmp(argv[1], "-V") == 0)
    {
      printf("0.0.1\n");
    }

    else if (remove(argv[1]) == -1)
    {
      printf("remove file fail check if the file exits\n");
    }
    else
    {
      printf("remove success\n");
    }
  }
}