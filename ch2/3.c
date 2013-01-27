/* Exercise 2-3
 * Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into
 * its equivalent integer value. The allowable digits are
 * 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <ctype.h>

unsigned int htoi(const char s[]);

int main(void)
{
	char *test[] =
	{
		"F00",
		"bar",
		"0100",
		"0x1",
		"0XA",
		"0X0C0E",
		"abcdef",
		"123456",
		"0x123456",
		"deadbeaf",
		"zog_c"
	};

	size_t numtests = sizeof(test) / sizeof(test[0]);
	size_t thistest;

	for (thistest = 0; thistest < numtests; thistest++)
	{
		printf("%s: %u\n", test[thistest], htoi(test[thistest]));
	}

	return 0;
}

unsigned int htoi(const char s[])
{
	unsigned int answer = 0;
	int i = 0;
	int valid = 1;

	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'x' || s[i] == 'X')
		{
			++i;
		}
	}

	while (valid && s[i] != '\0')
	{
		answer *= 16;
		if (isxdigit(s[i]))
		{
			if (isdigit(s[i]))
				answer += s[i] - '0';
			else
				answer += toupper(s[i]) - 'A' + 10;
		}
		else
			valid = 0;
		++i;
	}

	if (!valid)
		answer = 0;

	return answer;
}