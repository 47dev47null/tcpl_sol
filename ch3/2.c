/* Exercise 3-2
 * Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like
 * \n and \t as it copies the string t to s. Use a switch.
 * Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */

#include <stdio.h>

#define MAXLINE 1024

/* escape: converts characters like newline and tab into visible escape sequences */
void escape(char s[], char t[]);
/* escape: converts visible escape sequences into characters like newline and tab */
void unescape(char s[], char t[]);

int main(void)
{
	char t[] = "Hello\tWorld!\n";
	char s[MAXLINE];

	escape(s, t);
	printf("%s\n", s);
	unescape(t, s);
	printf("%s\n", t);

	return 0;
}

void escape(char s[], char t[])
{
	int i;
	int j;

	for (i = 0, j = 0; t[i] != '\0'; ++i)
	{
		switch (t[i])
		{
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
		}
	}
	s[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i;
	int j;

	for (i = 0, j = 0; t[i] != '\0'; ++i)
	{
		if (t[i] == '\\')
		{
			switch (t[i+1])
			{
				case 'n':
					s[j++] = '\n';
					++i;
					break;
				case 't':
					s[j++] = '\t';
					++i;
					break;
				default:
					s[j++] = '\\';
			}
		}
		else
		{
			s[j++] = t[i];

		}
	}
	s[j] = '\0';
}