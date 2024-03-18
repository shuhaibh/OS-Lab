#include«stdio.h>>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 100

int main()
{
  int fd;
  char buffer[BUFFER_SIZE];
  
  fd=open("Sample.txt" , 0_RDWR);
  if(fd==-1）
  {
    printf("Error opentng ftle!\n");
    exit(-1);
  }
  write（fd，"Hello\n",14;
  close(fđ);

  fd=open ("Sample. txt" ,0_RDONLY);
  if(fd==-1）
  {
    printf("Error opentng file!\n");
    exit(-1);
  }
  read(fd, buffer, BUFFER_SIZE);
  close(fd):
  printf("Data fron the file:-%s\n", buffer);
  
  return 0;
}
