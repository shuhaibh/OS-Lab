//program to implement page replacement algorithms
#include<stdio.h>

#define MAX 100

void fifo(int page[],int pages,int frames)
{
    printf("\t\tFIFO\n");
    int frame[MAX],i,j,k=0,pagefault=0;
    for(i=0;i<frames;i++)
    {
        frame[i]=-1;
    }
    
    for(i=0;i<pages;i++)
    {
        int found=0;
        printf("For %d: ",page[i]);
        for(j=0;j<frames;j++)
        {
            if(frame[j]==page[i])
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            frame[k]=page[i];
            k=(k+1)%frames;
            pagefault++;
            for(j=0;j<frames;j++)
            {
                if(frame[j]!=-1)
                {
                    printf("%d ",frame[j]);
                }
            }
        }
        else
        {
            printf("No page fault");
        }
        printf("\n");
    }
    printf("Total number of page faults: %d\n",pagefault);
}

void lru(int page[],int pages,int frames)
{
    printf("\t\tLRU\n");
    struct frame
    {
        int content,count;
    } frame[MAX];
    
    int i,j;
    for(i=0;i<frames;i++)
    {
        frame[i].content=-1;
        frame[i].count=0;
    }
    
    int cnt=1,pagefault=0,ind=0;
    for(i=0;i<pages;i++)
    {
        int found=0;
        printf("For %d: ",page[i]);
        for(j=0;j<frames;j++)
        {
            if(frame[j].content==page[i])
            {
                found=1;
                frame[j].count=cnt++;
            }
        }
        if(found==0)
        {
            if(ind<frames)
            {
                frame[ind].content=page[i];
                frame[ind].count=cnt++;
                ind++;
            }
            else
            {
                int min=0;
                for(j=1;j<frames;j++)
                {
                    if(frame[j].count<frame[min].count)
                    {
                        min=j;
                    }
                }
                frame[min].content=page[i];
                frame[min].count=cnt++;
            }
            pagefault++;
            
            for(j=0;j<frames;j++)
            {
                if(frame[j].content!=-1)
                {
                    printf("%d ",frame[j].content);
                }
            }
        }
        else
        {
            printf("No page fault");
        }
        printf("\n");
    }
    printf("Total number of page faults: %d",pagefault);
}

void lfu(int page[],int pages,int frames)
{
    printf("\t\tLFU\n");
    struct frame
    {
        int content,count,freq;
    } frame[MAX];
    
    int i,j;
    for(i=0;i<frames;i++)
    {
        frame[i].content=-1;
        frame[i].count=0;
        frame[i].freq=0;
    }
    
    int cnt=1,pagefault=0,ind=0;
    for(i=0;i<pages;i++)
    {
        int found=0;
        printf("For %d: ",page[i]);
        for(j=0;j<frames;j++)
        {
            if(frame[j].content==page[i])
            {
                frame[j].freq++;
                found=1;
                break;
            }
        }
        if(found==0)
        {
            if(ind<frames)
            {
                frame[ind].content=page[i];
                frame[ind].freq=1;
                frame[ind].count=cnt++;
                ind++;
            }
            else
            {
                int min=0;
                for(j=1;j<frames;j++)
                {
                    if(frame[j].freq<frame[min].freq || (frame[j].freq==frame[min].freq && frame[j].count<frame[min].count))
                    {
                        min=j;
                    }
                }
                frame[min].content=page[i];
                frame[min].freq=1;
                frame[min].count=cnt++;
            }
            pagefault++;
            
            for(j=0;j<frames;j++)
            {
                if(frame[j].content!=-1)
                {
                    printf("%d ",frame[j].content);
                }
            }
        }
        else
        {
            printf("No page fault");
        }
        printf("\n");
    }
    printf("Total number of page faults: %d",pagefault);
}

int main()
{
    int p[MAX],pno,f[MAX],fno,i;
    printf("Enter number of pages: ");
    scanf("%d",&pno);
    printf("Enter page sequence: ");
    for(i=0;i<pno;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d",&fno);
    
    fifo(p,pno,fno);
    lru(p,pno,fno);
    lfu(p,pno,fno);
    
    return 0;
}
