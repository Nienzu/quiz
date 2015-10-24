#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 2600
#define TARGET 'g'

char smallest_character(char str[], char c, int size);

int main()
{
    char input[MAX_SIZE];
    char c = TARGET;
    int size = 0;
    FILE *fp = fopen("test.txt", "r");
    while(fscanf(fp, "%c", &input[size]) != EOF)
        size++;
    char result = smallest_character(input, c, size);
    printf("Output : %c\n", result);

    return 0;
}


char smallest_character(char str[], char c, int size)
{
    int i;
    char result = '\0';
    for( i = 0 ; i < size; i++)
        if ( str[i] > c ) {
            result = str[i];
            break;
        }
    return (result == '\0') ? str[0] : result ;
}

