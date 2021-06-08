#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <pwd.h>
#include <string.h>
#include <wait.h>
#include <errno.h>
#include <sys/types.h>
#define Max 1024
char commands[1024][1024];
struct ps
{
   char *pw_name;
   char *pw_passwd;
   uid_t pw_uid;
   gid_t pw_gid;
   char *pw_gecos;
   char *pw_dir;
   char *pw_shell;
};
void getUserName()
{
   struct ps *pass;
   pass = getpwuid(getuid());
   printf("[%s@", pass->pw_name);
}
void GetHostName()
{
   char name[128];
   gethostname(name, sizeof(name) - 1);
   printf("%s", name);
}
void GetDir()
{
   char pwd[128];
   getcwd(pwd, sizeof(pwd) - 1);
   int len = strlen(pwd);
   char *p = pwd + len - 1;
   while (*p != '/' && len--)
   {
      p--;
   }
   p++;
   printf("%s]@", p);
}
void deleteChar(char buff[], int *idx)
{
   if (idx > 0)
   {

      memmove(buff + *idx - 1, buff + *idx, strlen(buff) - *idx + 1);
   }
   (*idx)--;
}
void insertChar(char buff[], char ch, int *idx)
{

   if (strlen(buff) < Max - 1)
   {

      memmove(buff + *idx + 1, buff + *idx, strlen(buff) - *idx + 1);
      buff[*idx] = ch;
      (*idx)++;
   }
}
void getInput(char buff[])
{
   char ch;
   int idx = 0;
   buff[0] = '\0';
   printf("\033[s");
   fflush(stdout);
   while (1)
   {
      ch = getchar();
      switch (ch)
      {
      case 127:
         deleteChar(buff, &idx);
         break;
      case '\n':
         return;
      default:
         insertChar(buff, ch, &idx);
         break;
      }
      fflush(stdout);
   }
}

void getCmd(char *buff, char *cmd[])
{
   int idx = 0;
   char *ret;

   ret = strtok(buff, " \t\n");
   while (1)
   {
      cmd[idx++] = ret;
      if (NULL == ret)
         return;
      ret = strtok(NULL, " \t\n");
   }
}
int main(void)
{
   printf("\n/*-------------------------------------------------*/\n");
   printf("实现的命令有 ls pwd cd echo mkdir rm cat ls wc\n");
   printf("exit 退出");
   printf("\n/*-------------------------------------------------*/\n");
   char buff[Max] = {0};
   char *cmd[20];
   char c[1024];
   char b[1024];
   char *argv[1024];
   int i = 0;
   while (1)
   {
      getUserName();
      GetHostName();
      GetDir();
      getInput(buff);
      getCmd(buff, cmd);
      if (NULL == cmd[0])
      {
         continue;
      }
      else if (strcmp(cmd[0], "pwd") == 0)
      {
         int id = fork();
         if (id == 0)
         {
            execl("/home/stu3929/lab2/myPwd", "pwd", cmd, NULL);
         }
         else
         {
            wait(0);
         }
      }
      else if (strcmp(cmd[0], "echo") == 0)
      {
         int id = fork();
         if (id == 0)
         {
            execv("/home/stu3929/lab2/myEcho", cmd);
         }
         else
         {
            wait(0);
         }
      }
      else if (strcmp(cmd[0], "rm") == 0)
      {
         int id = fork();

         if (id == 0)
         {
            execv("/home/stu3929/lab2/myRm", cmd);
         }
         else
         {
            wait(0);
         }
      }
      else if (strcmp(cmd[0], "mkdir") == 0)
      {
         int id = fork();
         if (id == 0)
         {
            execv("/home/stu3929/lab2/myMkdir", cmd);
         }
         else
         {
            wait(0);
         }
      }
      else if (strcmp(cmd[0], "cd") == 0)
      {

         chdir(cmd[1]);
      }
      else if (strcmp(cmd[0], "cat") == 0)
      {
         int id = fork();
         if (id == 0)
         {
            execv("/home/stu3929/lab2/myCat", cmd);
         }
         else
         {
            wait(0);
         }
      }
      else if (strcmp(cmd[0], "exit") == 0)
      {
         return 0;
      }
      else if (strcmp(cmd[0], "ls") == 0)
      {
         int id = fork();
         if (id == 0)
         {
            execv("/home/stu3929/lab2/myLs", cmd);
         }
         else
         {
            wait(0);
         }
      }
      else if (strcmp(cmd[0], "wc") == 0)
      {
         int id = fork();
         if (id == 0)
         {
            execv("/home/stu3929/lab2/myWc", cmd);
         }
         else
         {
            wait(0);
         }
      }
   }
}