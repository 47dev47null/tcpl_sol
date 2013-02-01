/* Exercise 3-6
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXLINE 1024

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main(void)
{
	char s[MAXLINE];

	printf("%d\n", INT_MIN);
	itoa(INT_MIN, s, 12);
	printf("%s\n", s);

	printf("%d\n", -43);
	itoa(-43, s, 10);
	printf("%s\n", s);

	return 0;

}

void itoa(int n, char s[], int width)
{
	int i, sign;

	i = 0;
	sign = n;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10);

	if (sign < 0)
		s[i++] = '-';

	// padding
	while (i < width)
		s[i++] = ' ';

	s[i] = '\0';

	reverse(s);
}

void reverse(char s[])
{
	int len;
	int i;
	char c;

	/* find the length of s */
	for (len = 0; s[len] != '\0'; ++len)
		;

	for (i = 0; i < len / 2; ++i)
	{
		c = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = c;
	}
}