//program to implement disk scheduling algorithm

#include<stdio.h>
#include<stdlib.h>

int n,values[10],initial,range[2],position=0;

void fcfs()
{
        printf("FCFS:\n");
        int i,seakt=0,current=initial;
        for(i=0;i<n;i++)
        {
                seakt+=abs(current-values[i]);
                current=values[i];
        }
        printf("Seek Time: %d\n",seakt);
}

void scan()
{
        printf("SCAN:\n");
        int i,j,seakt=0,temp;

        for(i=0;i<n;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(values[j]>values[j+1])
                        {
                                temp=values[j];
                                values[j]=values[j+1];
                                values[j+1]=temp;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(initial<values[i])
                {
                        position=i;
                        break;
                }
        }
        seakt+=abs(initial-range[1]);
        seakt+=abs(range[1]-values[0]);
        printf("Seak Time: %d\n",seakt);
}

void cscan()
{
        printf("C-SCAN\n");
        int seakt=0;
        seakt+=abs(initial-range[1]);
        seakt+=abs(range[1]-range[0]);
        seakt+=abs(range[0]-values[position]);
        printf("Seak Time: %d\n",seakt);
}

void look()
{
        printf("LOOK:\n");
        int seakt=0;
        seakt+=abs(initial-values[n-1]);
        seakt+=abs(values[n-1]-values[0]);
        printf("Seak Time: %d\n",seakt);
}

void clook()
{
        printf("C-LOOK\n");
        int seakt=0;
        seakt+=abs(initial-values[n-1]);
        seakt+=abs(values[n-1]-values[0]);
        seakt+=abs(values[0]-values[position]);
        printf("Seak Time: %d\n",seakt);
}

void main()
{
        int i;
        printf("Enter the number of cylinders:");
        scanf("%d",&n);
        printf("Enter the values of cylinders:");
        for(i=0;i<n;i++)
                scanf("%d",&values[i]);
        printf("Enter the value of initial position:");
        scanf("%d",&initial);
        printf("Enter Range:");
        for(i=0;i<2;i++)
                scanf("%d",&range[i]);

        fcfs();
        scan();
        cscan();
        look();
        clook();
}
