#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *output;
    output = fopen("test.txt", "w");
    unsigned seed;
    seed = (unsigned) time(NULL);
    srand(seed);
    int i;
    for(i = 0; i<100; i++)
        fprintf(output, "%d ", rand()%100 - rand()%100);
    fclose(output);
    return 0;
}
