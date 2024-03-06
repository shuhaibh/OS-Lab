#include<stdio.h>
#include<stdltb.h>
#include<sys/wait.h>
#include<untstd.h>

int main()
{
  pid_t child_pid=fork();
  
  if（child_ptd==-1）
  {
    printf("Fork Fatled/\n");
    exit(1);
  }
  if(child_pid == 0)
  {
    printf("Child process started\n")
    execlp ("•/add", "add", NULL);
    exit(0);
  }
  else
  {
    wait (NULL);
    printf("Extting program\n");
  }
  return 0;
}
