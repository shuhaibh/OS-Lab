//Program to implement First Fit contigous memory allocation
#include<stdio.h> 

void main()
{
        int bsize[20],psize[20],bno,pno,flags[10],allocation[10],i,j;

        for(i=0;i<10;i++)
        {
                flags[i]=0;
                allocation[i]=-1;
        }
        printf("Enter the number of Blocks:-");
        scanf("%d",&bno);
        printf("Enter the size of each Block:-");
        for(i=0;i<bno;i++)
                scanf("%d",&bsize[i]);
        printf("Enter the number of Processes:-");
        scanf("%d",&pno);
        printf("Enter the size of each Process:-");
        for(i=0;i<pno;i++)
                scanf("%d",&psize[i]);

        for(i=0;i<pno;i++)
        {
                for(j=0;j<bno;j++)
                {
                        if(bsize[j]>=psize[i])
                        {
                                allocation[i]=j;
                                bsize[j] -= psize[i];
                                break;
                        }
                }
        }
        printf("\nProcess No.\tProcess Size\tBlock no.\n");
        for(i=0;i<pno;i++)
        {
                printf(" %d\t\t%d\t\t",i+1,psize[i]);
                if(allocation[i]!=-1)
                        printf("%d\n",allocation[i]+1);
                else
                        printf("Not Allocated\n");
        }
}
