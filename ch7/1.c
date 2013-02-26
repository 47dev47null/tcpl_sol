/* Exercise 7-1
 * Write a program that converts upper case to lower or lower case to upper, 
 * depending on the name it is invoked with, as found in argv[0].
 */

/* Adopted function pointers from Richard Healthfield */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int (*convcase)(int);
    int ch;

    if (argc > 0)
    {
        convcase = strstr(argv[0], "upper") ? toupper : tolower;  

        while ((ch = getchar()) != EOF)
        {
            ch = convcase((unsigned char) ch);
            putchar(ch);
        }
    }
    else
    {
        fprintf(stderr, "Unknown name. Can't decide what to do.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
