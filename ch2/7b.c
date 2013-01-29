/* Solution by Gregory Pietsch
 * [src](http://users.powernet.co.uk//eton/kandr2/krx207.html)
 */

/* Exercise 2-7
 * Write a function invert(x,p,n) that returns x
 * with the right-adjusted n bits that begin at
 * position p inverted (i.e., 1 changed into 0 
 * and vice versa), leaving the others unchanged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
	unsigned x;
	int n;
	int p;

	x = 0x8FB;		/* 100011111011 */
	n = 5;
	p = 9;
	/* expected: 101100011011 (0xB1B) */
	printf("0x%x\n", invert(x, p, n));

	x = 0xB59;		/* 101101011001 */
	n = 3;
	p = 4;
	/* expected: 101101000101 (0xB45) */
	printf("0x%x\n", invert(x, p, n));

	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0U << n) << (p+1-n));
}