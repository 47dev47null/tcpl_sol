/* Exercise 3-5
 * Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s. In
 * particular, itob(n,s,16) formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define MAXLINE 1024

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
	char s[MAXLINE];

	printf("%d\n", INT_MIN);
	itob(INT_MIN, s, 10);
	printf("%s\n", s);

	printf("%o\n", INT_MIN);
	itob(INT_MIN, s, 8);
	printf("%s\n", s);

	printf("%x\n", INT_MIN);
	itob(INT_MIN, s, 16);
	printf("%s\n", s);

	printf("%d\n", -43);
	itob(-43, s, 10);
	printf("%s\n", s);

	printf("%o\n", -43);
	itob(-43, s, 8);
	printf("%s\n", s);

	printf("%x\n", -43);
	itob(-43, s, 16);
	printf("%s\n", s);	

	return 0;
}

void itob(int n, char s[], int b)
{
	assert(2 <= b && b <= 16);
	int i, sign;

	i = 0;
	sign = n;
	do
	{
		unsigned t = abs(n % b);
		s[i++] = t < 10 ? t + '0' : t - 10 + 'a';
	} while (n /= b);

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