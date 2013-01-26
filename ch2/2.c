/* Exercise 2-2
 * Write a loop equivalent to the for loop below without using && or || .
 * Here it the loop:
 *
 *     for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *         s[i] = c;
 *
 */

#include <stdio.h>

#define MAXLEN 1000

int main(void)
{
	int i = 0;
	int	lim = MAXLEN;
	int	c;
	char s[MAXLEN];

	while (i < lim - 1)
	{
		c = getchar();

		if (c == EOF)
			break;
		else if (c == '\n')
			break;

		s[i++] = c;
	}

	s[i] = '\0';   /* terminate the string */

	return 0;
}