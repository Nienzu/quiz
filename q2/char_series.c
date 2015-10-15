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
    int i, j;
    char c = 'a';
    for(i = 0; i < 26; i++)
        for(j = 0; i<rand()%100; j++)
            fprintf(output, "%c", c+i);

    fclose(output);
    return 0;
}
