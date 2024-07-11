//Program to implement Reader writer problem

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t mutex,wrt;
int rdc=0,data=0;

void *reading(void *arg)
{
    int read_id=*((int *)arg);
    while(1)
    {
    sleep(2);
    sem_wait(&mutex);
    rdc++;
    if(rdc==1)
    {
        sem_wait(&wrt);
    }
    sem_post(&mutex);
    printf("Reader %d read data :%d\n",read_id,data);
    sem_wait(&mutex);
    rdc--;
    if(rdc==0)
    {
        sem_post(&wrt);
        
    }
    sem_post(&mutex);
    }
    
}
void *writing(void *arg)
{
    int write_id=*((int *)arg);
    while(1)
    {
        sleep(2);
        data++;
        sem_wait(&wrt);
        printf("Writer %d writes data;%d\n",write_id,data);
        sem_post(&wrt);
    }
    
}
void main()
{
    int readers,writers;
    printf("Enter the no of readers:");
    scanf("%d",&readers);
    printf("Enter the no of writers:");
    scanf("%d",&writers);
    pthread_t Reader[readers],Writer[writers];
    int i,reader_id[readers],writer_id[writers];
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(i=0;i<readers;i++)
    {
        reader_id[i]=i+1;
        pthread_create(&Reader[i],NULL,reading,&reader_id[i]);
    }
     for(i=0;i<writers;i++)
    {
        writer_id[i]=i+1;
        pthread_create(&Writer[i],NULL,writing,&writer_id[i]);
    }
     for(i=0;i<readers;i++)
    {
      
        pthread_join(Reader[i],NULL);
    }
     for(i=0;i<writers;i++)
    {
      
        pthread_join(Writer[i],NULL);
        
        
}
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    
}
