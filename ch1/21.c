/* Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * with the minimum number of tabs and blanks to achieve
 * the same spacing. Use the same stops as for detab.
 * When either a tab or a single blank would suffice to 
 * reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TABSTOP 4

int main(void)
{
	size_t spaces = 0;
	size_t x = 0;		/* position in the line */
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			spaces++;
		else if (spaces == 0)
		{
			putchar(c);
			x++;
		}
		else if (spaces == 1)
		{
			putchar(' ');
			putchar(c);
			spaces = 0;
			x += 2;
		}
		else
		{
			while (x / TABSTOP != (x + spaces) / TABSTOP)
			{
				putchar('\t');
				x++;
				spaces--;	/* break the loop, let it go into the while */
				while (x % TABSTOP != 0)
				{
					x++;
					spaces--;
				}
			}

			for (; spaces > 0; ++x, --spaces)
				putchar(' ');

			putchar(c);
			x++;
		}
		if (c == '\n')
			x = 0;
	}

	return 0;
}