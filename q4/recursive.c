#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ARR 100

int maxSubArray(int arr[], int l, int h);
int max_2(int a, int b)
{
    return a > b? a : b;
}
int max_3(int a, int b, int c)
{
    return max_2(a, b) > c? max_2(a, b) : c;
}
int maxCrossingSum(int arr[], int l, int m, int h);

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    int i = 0;
    int A[MAX_ARR];
    while(fscanf(fp, "%d", &A[i]) != EOF)
        i++;
    printf("%d\n", i);
    fclose(fp);


    int max_sum;
    max_sum = maxSubArray(A, 0, i-1);
    printf("%d\n", max_sum);
    return 0;
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    int i;
    for(i = m; i >= l; i--) {
        sum += arr[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(i = m + 1; i <= h; i++) {
        sum += arr[i];
        if(sum > right_sum)
            right_sum = sum;
    }

    return right_sum + left_sum;
}

int maxSubArray(int arr[], int l, int h)
{
    if(l == h)
        return arr[l];
    int m = (l + h)/2;

    return max_3(maxSubArray(arr, l, m), maxSubArray(arr, m+1, h), maxCrossingSum(arr, l, m, h));
}
