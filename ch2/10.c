/* Exercise 2-10
 * Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

char lower(char c);

int main(void)
{
	printf("%c\n", lower('A'));
	return 0;
}

char lower(char c)
{
	return 'A'<= c && c <= 'Z' ? c + ('a'-'A') : c;
}