/* Exercise 2-9
 * In a two's complement number system, x &= (x-1)
 * deletes the rightmost 1-bit in x. Explain why.
 * Use this observation to write a faster version of bitcount.
 */

#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x);

int main(void)
{
	unsigned x;

	x = 0x8FB;		/* 100011111011 */
	printf("%d\n", bitcount(x));		/* expected: 8 */

	x = 0xB59;		/* 101101011001 */
	printf("%d\n", bitcount(x));		/* expected: 7 */

	return 0;
}

int bitcount(unsigned x)
{
	unsigned b;

	for (b = 0; x != 0U; x &= (x-1))
		++b;

	return b;
}