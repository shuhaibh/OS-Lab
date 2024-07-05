//Program to implement Worst Fit contigous memory allocation

#include<stdio.h>

int main()
{
        int bsize[20],psize[20],bno,pno,i,j,all[20];

        printf("Enter the number of Blocks:");
        scanf("%d",&bno);
        printf("Enter the size of blocks:");
        for(i=0;i<bno;i++)
                scanf("%d",&bsize[i]);
        printf("Enter the number of Processes");
        scanf("%d",&pno);
        printf("Enter the size of Processes:");
        for(i=0;i<pno;i++)
        {
                scanf("%d",&psize[i]);
                all[i]=-1;
        }

        for(i=0;i<pno;i++)
        {
                int worstplace=-1;
                for(j=0;j<bno;j++)
                {
                        if(bsize[j]>psize[i])
                        {
                                if(worstplace==-1)
                                        worstplace=j;
                                else if(bsize[worstplace]<bsize[j])
                                        worstplace=j;
                        }
                }
                if(worstplace!=-1)
                {
                        all[i]=worstplace;
                        bsize[worstplace]-=psize[i];
                }
        }
        printf("\nProcess No.\tProcess Size\tBlock no.\n");
        for(i=0;i<pno;i++)
        {
                printf("%d\t\t%d\t\t",i+1,psize[i]);
                if(all[i]!=-1)
                        printf("%d\n",all[i]+1);
                else
                        printf("Not allocated\n");
        }

}
