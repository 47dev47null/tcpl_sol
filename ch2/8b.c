/* Solution by Bob Wightman
 * [src](http://users.powernet.co.uk/eton/kandr2/krx208.html)
 */

/* Exercise 2-8
 * Write a function rightrot(x,n) that returns the value
 * of the integer x rotated to the right by n bit positions.
 */

#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, unsigned n);

int main(void)
{
	unsigned x;
	unsigned n;

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

unsigned rightrot(unsigned x, unsigned n)
{
   /* calculate number of bits in type */
   size_t s = sizeof(x) * CHAR_BIT;
   size_t p;

   /* limit shift to range 0 - (s - 1) */
   if(n < s)
       p = n; 
   else
       p = n % s;

   /* if either is zero then the original value is unchanged */
   if((0 == x) || (0 == p))
       return x;

   return (x >> p) | (x << (s - p));
}