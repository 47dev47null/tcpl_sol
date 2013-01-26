/* Exercise 1-23
 * Write a program to remove all comments from
 * a C program. Don't forget to handle quoted
 * strings and character constants properly.
 * C comments do not nest.
 */

#include <stdio.h>

#define BUFSIZE 1000

int obtenirline(char s[], int lim);

int main(void)
{
	int len;
	char line[BUFSIZE];
	int comment;		/* flag, 0 represents not in comment, 
						 * '/' represents comment beginning with //,
						 * '*' represents comment beginning with /*
						 */
	int string;			/* flag, 0 represnts not in string,
						 * ''' represents string beginning with ',
						 * '"' represents string beginning with "
						 */
	int i;

	comment = string = 0;
	while ((len = obtenirline(line, BUFSIZE)) > 0)
	{
		for (i = 0; i < len; ++i)
		{	
			if (!comment && !string && line[i] == '/' && line[i+1] == '/')
			{	/* start of comment */
				continue;	/* drop the rest of the line */
			}
			else if (!comment && !string && line[i] == '/' && line[i+1] == '*')
			{	/* start of comment */
				++i;	/* skip next asterisk */
				comment = '*';
			}
			else if (comment == '*' && line[i] == '*' && line[i+1] == '/')
			{	/* end of comment */
				++i;	/* skip next slash */
				comment = 0;
			}
			else if (!comment && !string && line[i] == '"')
			{	/* start of string */
				string = '"';
				putchar('"');
			}
			else if (!comment && !string && line[i] == '\'')
			{	/* start of string */
				string = '\'';
				putchar('\'');
			}
			else if (!comment && string == line[i]
				&& (line[i-1] != '\\' || (line[i-1] == '\\' && line[i-2] == '\\')))
				/* make sure not escaped by \ */
			{	/* end of string */
				string = 0;
				putchar(line[i]);
			}
			else if (!comment)
				putchar(line[i]);
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