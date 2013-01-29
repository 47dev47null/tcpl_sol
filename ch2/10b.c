/* Solution by Bryan Williams
 * [src](http://users.powernet.co.uk/eton/kandr2/krx210.html)
 */

/* Exercise 2-10
 * Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */


/*
 * the more portable solution, requiring string.h for strchr but keeping the idea of a 
 * conditional return.  
 */

#include <stdio.h>
#include <string.h>

/* lower: convert c to lower case */
int lower(int c);

int main(void)
{
	printf("%c\n", lower('A'));
	return 0;
}

int lower(int c)
{
	char *Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *Lowercase = "abcdefghijklmnopqrstuvwxyz";
	char *p = NULL;

	return NULL == (p = strchr(Uppercase, c)) ? c : *(Lowercase + (p - Uppercase));
}