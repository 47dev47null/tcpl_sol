/* Exercise 2-4
 * Write an alternate version of squeeze(s1, s2) that
 * deletes each character in the string s1 that matches
 * any character in the string s2.
 * 
 * Here is the squeeze in the book:
 *
 *     void squeeze(char s[], int c)
 *     {
 *	       int i, j;
 *         for (i = j = 0; s[i] != '\0'; i++)
 *         {
 *             if (s[i] != c)
 *                 s[j++] = s[i];
 *         }
 *		   s[j] = '\0';
 *     }
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
	char s1[] = "The C Programming Language";
	char s2[] = "gram age";

	squeeze(s1, s2);
	printf("%s\n", s1);

	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; i++)
	{
		for (k = 0; s2[k] != '\0'; k++)
		{
			if (s1[i] == s2[k])
				break;
		}
		if (s2[k] == '\0')		/* not matches any character in the string s2 */
		{
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}