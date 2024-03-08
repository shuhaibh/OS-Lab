#include<stdtio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  pid_t child_pid=fork();
  if（child_pid==-1）
  {
    printf("Fork Failed!");
    exit(1);
  }
  if(child_pid == 0)
  {
    printf("Child Process:-%d\t Parent Process:-%d"\n ,getpid(),getppid()):
    exit(0);
  else
  {
    int status;
    waitpid(child_pid, &status,0);
    printf ("Parent Process: -%d\t Child Process:-%d\n",getpid(),child_pid);
  }
return 0;
}
