#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TARGET 'g'
#define MAX_SIZE 2600

char smallest_character(char str[], char c, int start, int end);

int main()
{
    char input[MAX_SIZE];
    int size = 0;
    FILE *fp = fopen("test.txt", "r");
    while(fscanf(fp, "%c", &input[size]) != EOF)
        size++;
    char r = smallest_character(input, TARGET, 0, size);
    printf("Output : %c\n", r);
    fclose(fp);
    return 0;
}

char smallest_character(char str[], char c, int start, int end)
{
    int checkpoint;
    checkpoint = (start + end)/2;
    char result = '\0';

    if ((start + 1) != end) {
        if(str[checkpoint] > c)
            result = smallest_character(str, c, start, checkpoint);
        else if(str[checkpoint] <= c)
            result = smallest_character(str, c, checkpoint, end);
    } else {
        if(str[start] > c)
            return str[start];
        else if(str[end] > c)
            return str[end];
        else
            return str[0];
    }

    return result;
}
