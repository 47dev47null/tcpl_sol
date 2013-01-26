/* Exercise 1-22
 * Write a program to "fold" long input lines into 
 * two or more shorter lines after the last non-blank
 * character that occurs before the n-th column of
 * input. Make sure your program does something
 * intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define OUT 0
#define IN 1
#define BUFSIZE 1000
#define COLWIDTH 60

int obtenirline(char s[], int lim);
int discard_newline(char s[], int len);

int main(void)
{
	int len;
	char line[BUFSIZE];
	int i, j, p, col;

	col = p = 0;
	while ((len = obtenirline(line, BUFSIZE)) > 0)
	{
		p = 0;
		if (len == 1)	/* reserve paragraph structures */
		{
			printf("\n\n");
			col = 0;
			continue;
		}
		len = discard_newline(line, len);		/* remove original '\n', insert manually */
		while (len - p >= COLWIDTH - col)
		{
			/* insert a newline near the COLWIDTH */
			/* assume there is no word's length exceeds the COLWIDTH */
			for (i = COLWIDTH - col - 1; i >= 0 && line[p+i] != ' '; --i)
				;	/* fold at left */
			for (j = COLWIDTH - col - 1; j < len - p && line[p+j] != ' '; ++j)
				;	/* fold at right */
			i = ((i + j) / 2 > COLWIDTH - col - 1) ? i : j;
			while (i-- >= 0)
				putchar(line[p++]);

			col = 0;
			putchar('\n');
		}
		for (; p < len; ++p, ++col)
		{
			putchar(line[p]);
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

/* discard_newline: remove '\n' (if any) */
int discard_newline(char s[], int len)
{
	if (s[len - 1] == '\n')
		s[--len] = '\0';
	return len;
}