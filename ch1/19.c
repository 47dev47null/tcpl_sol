/* Exercise 1-19
 * Write a function reverse(s) that reverses
 * the character string s. Use it to write a
 * program that reverses its input a line at
 * a time.
 */

#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);
int obtenirline(char s[], int lim);

int main(int argc, char *argv[])
{
	int len;
	char line[MAXLINE];

	while ((len = obtenirline(line, MAXLINE)) > 0)
	{
		if (line[len - 1] != '\n')
			reverse(line);
		else
		{
			line[len - 1] = '\0';
			reverse(line);
			line[len - 1] = '\n';
		}
		printf("%s", line);
	}

	return 0;
}

void reverse(char s[])
{
	int j;
	for (j = 0; s[j] != '\0'; ++j)
		;	/* find out the length of the string */

	char c;
	int i;
	for (i = 0; i < j/2; ++i)
	{
		c = s[i];
		s[i] = s[(j - 1) - i];
		s[(j - 1) - i] = c;
	}
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