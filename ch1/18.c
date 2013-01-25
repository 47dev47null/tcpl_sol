/* Exercise 1-18
 * Write a program to remove all trailing blanks
 * and tabs from each line of input, and to delete
 * entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int obtenirline(char line[], int maxline);
void trimline(char line[], int len);

int main(int argc, char *argv[])
{
	int len;
	char line[MAXLINE];

	while ((len = obtenirline(line, MAXLINE)) > 0)
	{
		if (len > 1)	/* not a blank line */
			trimline(line, len);
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

/* trimline: remove trailing blanks and tabs, 
 * arg 'len' is the length of the line,
 * print result to stdout.
 */
void trimline(char line[], int len)
{
	int i;
	for (i = len - 2; line[i] == ' ' || line[i] == '\t'; --i)
		;

	line[++i] = (line[len - 1] == '\n') ? '\n' : '\0';
	if (line[i] == '\n')
		line[++i] = '\0';

	if (i != 1)		/* not a line with blanks and tabs followed by '\n' */
		printf("%s", line);
}