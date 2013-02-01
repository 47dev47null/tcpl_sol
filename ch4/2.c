/* Exercise 4-2
 * Extend atof to handle scientific notation of
 * the form 123.45e-6 where a floating-point
 * number may be followed by e or E and an optionally
 * signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]);

int main()
{
	char *strings[] = {
		"1.0e43",
		"999.999",
		"123.456e-9",
		"-1.2e-3",
		"1.2e-3",
		"-1.2E3",
		"-1.2e03",
		"cat",
		"",
		0
	};
	int i;

	for (i = 0; *strings[i]; ++i)
		printf("atof(%s) = %g\n", strings[i], atof(strings[i]));
	return 0;
}

double atof(char s[])
{
	double val;
	int power;
	int power_sig;	/* power of significand. e.g. 123.45e-6 has power_sig 2 */
	int power_exp;	/* power of absolute exponent. e.g. 123.45e-6 has power_exp 6 */
	int sign_sig;		/* sign of significand. e.g. 123.45e-6 has sign_sig 1 */
	int sign_exp;		/* sign of significand. e.g. 123.45e-6 has sign_exp -1 */
	int i;

	for (i = 0; isspace(s[i]); ++i)		/* skip white space */
		;

	sign_sig = s[i] == '-' ? -1 : 1;

	if (s[i] == '-' || s[i] == '+')
		++i;
	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		++i;
	for (power_sig = 0; isdigit(s[i]); ++i)
	{
		val = 10.0 * val + (s[i] - '0');
		++power_sig;
	}

	if (s[i] == 'e' || s[i] == 'E')
		++i;

	sign_exp = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;

	for (power_exp = 0; isdigit(s[i]); ++i)
		power_exp = 10 * power_exp + (s[i] - '0');

	power = sign_exp * power_exp - power_sig;
	if (power < 0)
	{
		while (power++ < 0)
			val /= 10.0;
	}
	else
	{
		while (power-- > 0)
			val *= 10.0;
	}

	return sign_sig * val;
}