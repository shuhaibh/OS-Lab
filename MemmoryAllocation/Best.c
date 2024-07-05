//Program to implement Best Fit contigous memmory allocation

#include <stdio.h>

int main() {
    int bsize[20], psize[20], bno, pno, temp, lowest = 9999, fragment[20], i, j;
    static int barray[20], parray[20];

    printf("Enter the number of Blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each Block:\n");
    for (i = 1; i <= bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter the number of Processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each Process:\n");
    for (i = 1; i <= pno; i++)
        scanf("%d", &psize[i]);

    for (i = 1; i <= pno; i++) {
        for (j = 1; j <= bno; j++) {
            if (barray[j] != 1) {  // If block j is not already allocated
                temp = bsize[j] - psize[i];
                if (temp >= 0 && temp < lowest) {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 9999;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= pno && parray[i] != 0; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, psize[i], parray[i], bsize[parray[i]], fragment[i]);
    }

    return 0;
}
