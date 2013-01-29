/* Exercise 2-8
 * Write a function rightrot(x,n) that returns the value
 * of the integer x rotated to the right by n bit positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
	unsigned x;
	int n;

	x = 0x8FB;		/* 100011111011 */
	n = 5;
	/* expected: 11011(0)*[20]1000111 (0xD8000047) */
	printf("0x%x\n", rightrot(x, n));

	x = 0xB59;		/* 101101011001 */
	n = 3;
	/* expected: 001(0)*[20]101101011 (0x2000016B) on 64-bit machine */
	printf("0x%x\n", rightrot(x, n));

	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	unsigned mask = ~0U >> 1;	/* 0x7fffffff on 64-bit machine */
	for (; n > 0; --n)
	{
		if ((x & 1) == 0)
			x = (x >> 1);
		else
			x = (x >> 1) | ~mask;
	}
	return x;
}