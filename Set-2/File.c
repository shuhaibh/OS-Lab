#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
int main()
{
  DIR *d;
  int exist;
  struct stat filestat;
  struct dirent *de;
  
  d=opendir (".");  
  if(d==NULL)
  {
    printf ("Current directory not opened!\n");
    exit(1);
  }
  else
  {
    for(de=readdir(d);de!=NULL;de=readdir(d))
    {
      exist=stat(de-›d_name,&filestat);
      if(exist<0)
      {
        printf("%s not found",de->d_name);
      }
      else
      {
        printf("---file name: -%s\n",de->d_name);
        printf("Size:-%ld bytes\n",filestat.st_size);
        printf("Owner UID:-%d\n",filestat.st_uid);
        printf("Group GID:-%d\n",filestat.st_gid);
      }
    }
  }
  closedir(d);
｝
