/* Exercise 3-4
 * In a two's complement number representation, our version of itoa
 * does not handle the largest negative number, that is, the value
 * of n equal to -(2 to the power (wordsize - 1)). Explain why not.
 * Modify it to print that value correctly regardless of the machine
 * on which it runs.
 */

/*
	void itoa(int n, char s[])
	{
		int i, sign;

		if ((sign = n) < 0)
			n = -n;
		i = 0;
		do
		{
			s[i++] = n % 10 + '0';
		} while ((n /= 10) > 0);
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}
 */

/* Explain:
 * when n equal to -(2 to the power (wordsize - 1)), -n exceeds
 * the maximum value in two's complement number representation.
 * e.g. in 5 bits two's complement number representation:
 * 01111 (15) is the maximum number,
 * 10000 (-16) is the minimum number.
 * That is, 16 exceeds the maximum number.
 */

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1024

void itoa(int n, char s[]);
void itoa_helper(int n, char s[]);
void reverse(char s[]);
void itoa_origin(int n, char s[]);

int main(void)
{
	char s[MAXLINE];

	printf("%d\n", INT_MIN);

	itoa_origin(INT_MIN, s);
	printf("origin: %s\n", s);

	itoa(INT_MIN, s);
	printf("revised: %s\n", s);

	return 0;
}

void itoa(int n, char s[])
{
	itoa_helper(n, s);
	reverse(s);
}

void itoa_helper(int n, char s[])
{
	int i;
	int sign;

	i = 0;
	if (n == INT_MIN)		/* handle special case when n equal to INT_MIN */
	{
		itoa_helper(n+1, s);
		/* revision: increment the unsigned part */
		int carry = 0, j = 0;
		do
		{
			if (s[j] == '9')
			{
				s[j++] = '0';
				carry = 1;
			}
			else
				s[j++]++;
		} while(carry != 0);
	}
	else
	{
		if ((sign = n) < 0)
			n = -n;
		do
		{
			s[i++] = n % 10 + '0';
		} while ((n /= 10) > 0);
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
	}
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

void itoa_origin(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
}