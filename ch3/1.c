/* Exercise 3-1
 * Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop
 * and measure the difference in run-time.
 */

#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

int main(void)
{
	int array[] = {1, 4, 6, 8, 9, 11, 15};
	int x1 = 1;
	int x2 = 6;
	int x3 = 15;
	int x4 = 0;
	int x5 = 16;

	printf("%d\n", binsearch(x1, array, 7));	/* expect: 0 */
	printf("%d\n", binsearch(x2, array, 7));	/* expect: 2 */
	printf("%d\n", binsearch(x3, array, 7));	/* expect: 6 */
	printf("%d\n", binsearch(x4, array, 7));	/* expect: -1 */
	printf("%d\n", binsearch(x5, array, 7)); 	/* expect: -1 */

	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	/* if x exists, its subscript must be mid, low or high */
	if (v[mid] == x)
		return mid;
	else if (v[low] == x)
		return low;
	else if (v[high] == x)
		return high;
	else
		return -1;
}