/* Solution by Paul Griffiths
 * [src](http://users.powernet.co.uk/eton/kandr2/krx304.html)
 */

/* Exercise 3-4
 * In a two's complement number representation, our version of itoa
 * does not handle the largest negative number, that is, the value
 * of n equal to -(2 to the power (wordsize - 1)). Explain why not.
 * Modify it to print that value correctly regardless of the machine
 * on which it runs.
 */

/* We can remedy these two bugs in the following way:
 * 1 - change 'while ((n /= 10) > 0)' to 'while (n /= 10)'.
 * Since any fractional part is truncated with integer division,
 * n will eventually equal zero after successive divides by 10,
 * and 'n /= 10' will evaluate to false sooner or later.
 * 2 - change 'n % 10 + '0'' to 'abs(n % 10) + '0'', to get the
 * correct character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXLINE 1024

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	char s[MAXLINE];

	printf("%d\n", INT_MIN);
	itoa(INT_MIN, s);
	printf("%s\n", s);

	return 0;
}

void itoa(int n, char s[])
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