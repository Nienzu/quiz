#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 2600
#define TARGET 'z'

char smallest_character(char str[], char c);

int main()
{
    char line[MAX_SIZE];
    char c = TARGET;
    int i = 0;
    FILE *fp = fopen("test.txt", "r");

    while (fgets(line, sizeof(line), fp)) {
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        i = 0;
    }
    char result = smallest_character(line, c);
    printf("Output : %c\n", result);

    return 0;
}


char smallest_character(char str[], char c)
{
    int i;
    char result = '\0';
    for( i = 0 ; 'a'<=str[i] || str[i]>='z'; i++)
        if ( str[i] > c ) {
            result = str[i];
            break;
        }
    return (result == '\0') ? str[0] : result ;
}

