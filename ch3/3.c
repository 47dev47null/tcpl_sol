/* Exercise 3-3
 * Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent
 * complete list abc...xyz in s2. Allow for letters of
 * either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 * or trailing - is taken literally.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1024

/* expand: expands shorthand notations in s1 into equivalent complete list in s2 */
void expand(char s1[], char s2[]);

int main(void)
{
	char s1[] = "a-zA-Z0-9\n" "a-z-\n" "z-a-\n"
				"-1-6-\n" "a-ee-a\n" "a-R-L\n"
				"1-9-1\n" "5-5";
	char s2[MAXLINE];

	expand(s1, s2);
	printf("%s\n", s2);

	return 0;
}

void expand(char s1[], char s2[])
{
	int i;
	int j;

	for (i = 0, j = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == '-' && i - 1 >= 0 && isalnum(s1[i-1]))
		{
			int m, n;
			if (isupper(s1[i-1]))
			{
				for (m = i; s1[m] == '-' && s1[m+1] >= s1[m-1]
					 && isupper(s1[m+1]); m = m + 2)
					;		/* handle shorthand like A-B-D */
			}
			else if (islower(s1[i-1]))
			{
				for (m = i; s1[m] == '-' && s1[m+1] >= s1[m-1]
					 && islower(s1[m+1]); m = m + 2)
					;		/* handle shorthand like a-b-d */
			}
			else
			{
				for (m = i; s1[m] == '-' && s1[m+1] >= s1[m-1]
					 && isdigit(s1[m+1]); m = m + 2)
					;		/* handle shorthand like 1-3-7 */
			}

			for (n = s1[i-1] + 1; n <= s1[m-1]; ++n)
				s2[j++] = n;

			s2[j++] = s1[m];	/* avoid infinite looping like 1-3-7-a */
			i = m;
		}
		else
		{
			s2[j++] = s1[i];
		}
	}

	s2[j] = '\0';
}