#include<stdio.h>
int main()
{
    int n,m,i,j,k;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&m);

    int allocation[n][m],maximum[n][m];
    int available[m];

    printf("Input values in allocation matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("Input values in maximum matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&maximum[i][j]);
        }
    }
    printf("Input values in available array\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }

    int f[n],ans[n],ind=0;
    for(k=0;k<n;k++)
    {
        f[k]=0;
    }

    int need[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=maximum[i][j]-allocation[i][j];
        }
    }

    int y=0;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[ind++]=i;
                    for(y=0;y<m;y++)
                    {
                        available[y]+=allocation[i][y];
                    }
                    f[i]=1;
                }
            }
        }
    }
    int flag=1;
    for(i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("The system is in unsafe state\n");
            break;
        }
    }
    if(flag==1)
    {
        printf("Safe Sequence is\n");
        for(i=0;i<n-1;i++)
        {
            printf("P%d->",ans[i]);
        }
        printf("P%d\n",ans[n-1]);}return 0;}
