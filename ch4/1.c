/* Exercise 4-1
 * Write the function strrindex(s, t), which returns the
 * position of the rightmost occurrence of t in s,
 * or -1 if there is none.
 */

#include <stdio.h>

/* strrindex: returns the position of the rightmost occurrence of t in s */
int strrindex(char s[], char t[]);

int main(void)
{
	char s[] = "I would forgive you if you could forgive me, could you?\n";
	char t[] = "ould";

	printf("%d\n", strrindex(s, t));

	return 0;
}

int strrindex(char s[], char t[])
{
	int i, j, k, kr;

	k = kr = -1;
	for (i = 0; s[i] != '\0'; ++i)
	{
		for (k = i, j = 0; s[k] == t[j]; ++k, ++j)
			;
		if (j > 0 && t[j] == '\0')
			kr = i;
	}

	return kr;
}
