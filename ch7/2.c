/* Exercise 7-2
 * Write a program that will print arbitrary input in a sensible way. As a 
 * minimum, it should print non-graphic characters in octal or hexadecimal 
 * according to local custom, and break long text lines.
 */

#include <stdio.h>
#include <ctype.h>

#define SPLIT   79 

int main(int argc, char *argv[])
{
    int c;
    int currlen;
    char *format;

    while (--argc && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
                case 'o': case 'O':
                    format = "%3o ";
                    break;
                case 'x': case 'X':
                    format = "%02X ";
                    break;
                default:
                    fprintf(stderr, "Illegal option %c\n", c);
                    break;
            }

    currlen = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            putchar(c);
            currlen = 0;
        }
        else if (isprint(c))
        {
            if (currlen + 1 > SPLIT)
            {
                putchar('\n');
                currlen = 0;
            }
            putchar(c);
            currlen++;
        }
        else
        {
            if (currlen + 4 > SPLIT)    /* non-printable character occupy 4 width */
            {
                putchar('\n');
                currlen = 0;
            }
            printf(format, c);
            currlen += 4;
        }
    }

    return 0;
}
