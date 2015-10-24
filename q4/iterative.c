#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ARR 100

int maxSubArray(int A[], int size);

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    int A[MAX_ARR];
    int i = 0;
    while(fscanf(fp, "%d", &A[i]) != EOF) {
        printf("%d ", A[i]);
        i++;
    }
    fclose(fp);
    int max;
    printf("\n%d\n", i);
    max = maxSubArray(A, i);
    printf("%d\n", max);
    return 0;
}

int maxSubArray(int A[], int size)
{
    int i, j, k;
    int temp = 0;
    int sum = INT_MIN;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size - i; j++) {
            for(k = j; k < j + i; k++)
                temp += A[k];
            if(temp > sum)
                sum = temp;
            printf("%d ", temp);
            temp = 0;

        }
    }

    return sum;
}