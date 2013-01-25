/* Exercise 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next
 * tab stop. Assume a fixed set of tab stops, say every
 * n columns.
 */

#include <stdio.h>

#define BUFSIZE   1000
#define SPACE     ' '
#define TAB       '\t'

int obtenirline(char s[], int lim);

int main(void)
{
    char line[BUFSIZE];
    int tab_size = 5;
    int i, j, k, l;

    while (obtenirline(line, BUFSIZE) > 0)
    {
        for (i = 0, l = 0; line[i] != '\0'; i++)
        {
            if (line[i] == TAB)
            {
                j = tab_size - l % tab_size;
                for (k = 0; k < j; k++)
                {
                    putchar(SPACE);
                    l++;
                }
            }
            else
            {
                putchar(line[i]);
                l++;
            }
        }
    }

    return 0;
}

int obtenirline(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';

    return i;
}