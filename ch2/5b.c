/* Solution by Partha Seetala
 * [src](http://users.powernet.co.uk//eton/kandr2/krx205.html)
 */

/* It works in a very interesting way.
 * He first defines an array with one element
 * for each possible character in the character set,
 * and then takes the second string and 'ticks' the
 * array at each position where the second string
 * contains the character corresponding to that position.
 * It's then a simple matter to loop through the first
 * string, quitting as soon as he hits a 'ticked' position in the array.
 */

#include <stdio.h>
#include <limits.h>

int any(char s1[], char s2[]);

int main(void)
{
	char s1[] = "function";
	char s2[] = "long";

	printf("%d\n", any(s1, s2));

	return 0;
}

int any(char s1[], char s2[])
{
	unsigned char array[UCHAR_MAX+1] = {0};
	int i;

	if (s1 == NULL)
	{
		if (s2 == NULL)
		{
			return 0;
		}
		else
			return -1;
	}

	for (i = 0; s2[i] != '\0'; ++i)
	{
		array[s2[i]] = 1;
	}

	for (i = 0; s1[i] != '\0'; ++i)
	{
		if (array[s1[i]] == 1)
			return i;
	}

	return -1;
}
