#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 9

int maxSubArray(int A[]);

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    int A[MAX_ARR];
    int i;
    for(i = 0; i < MAX_ARR; i++)
        fscanf(fp, "%d", &A[i]);
    fclose(fp);
    int max;
    max = maxSubArray(A);
    printf("%d\n", max);
    return 0;
}

int maxSubArray(int A[])
{
    int i, j, k;
    int temp = 0;
    int sum = 0;
    for(i = 0; i < MAX_ARR; i++) {
        for(j = 0; j < (MAX_ARR - i); j++)
            for(k = j; k < j+i; k++)
                temp +=A[k];
        if(temp > sum)
            sum = temp;
        temp = 0;
    }

    return sum;
}