/* Exercise 2-6
 * Write a function setbits(x,p,n,y) that returns
 * x with the n bits that begin at position p set
 * to the rightmost n bits of y, leaving the other
 * bits unchanged.
 */

#include <stdio.h>

/* getbits: get n bits from position p, right-adjusted */
unsigned getbits(unsigned x, int p, int n);

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
	unsigned x;
	unsigned y;
	int n;
	int p;

	x = 0x8FB;		/* 100011111011 */
	y = 0xD7;		/* 11010111 */
	n = 5;
	p = 9;
	/* expected: 101011111011 (0xAFB) */
	printf("0x%x\n", setbits(x, p, n, y));

	x = 0xB59;		/* 101101011001 */
	y = 0x59;		/* 01011001 */
	n = 3;
	p = 4;
	/* expected: 101101000101 (0xB45) */
	printf("0x%x\n", setbits(x, p, n, y));

	return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/* set right-adjusted n bits started from p in x to 0 */
	x = x & ~(~(~0 << n) << (p+1-n));
	/* get rightmost n bits of y */
	y = getbits(y, n-1, n);
	/* get result */
	x = x + (y << (p+1-n));

	return x;
}