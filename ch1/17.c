/* Exercise 1-17
 * Write a program to print all input lines
 * that are longer than 80 characters.
 */

#include <stdio.h>

#define THRESHOLD 80    /* filter value */
#define MAXLINE 1000    /* maximum input line length */

int obtenirline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char *argv[])
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = obtenirline(line, MAXLINE)) > 0)
    {
        if (len > THRESHOLD)
        {
            printf("length: %d\n%s\n", len, line);
        }
    }

    return 0;
}

/* obtenirline: read a line into s, return length */
int obtenirline(char s[], int lim)
{
    int c, i, j;    /* i stores max len, j stores string index */

    for (i = 0, j = 0; (c = getchar()) != '\n' && c != EOF; ++i)
    {
        if (j < lim - 1)    /* stop recording when reaching buffer length constraint */
            s[j++] = c;
    }
    if (c == '\n')
    {
        if (j < lim - 1)
            s[j++] = '\n';
        ++i;
    }
    s[j] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    for (i = 0; (to[i] = from[i]) != '\0'; i++)
      ;
}