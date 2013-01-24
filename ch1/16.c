/* Exercise 1-16
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrarily
 * long input lines, and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 10  /* maximum input line length */

int obtenirline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char *argv[])
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = obtenirline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)    /* when there was a line */
        printf("length: %d\nline: %s\n", max, longest);
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