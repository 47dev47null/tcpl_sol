/* Exercise 4-5
 * Add access to library functions like sin, exp, and pow.
 * See <math.h> in Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define FUNC '1'

int getop(char []);
void push(double);
double pop(void);
void func(char []);

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		printf("%s\n", s);
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case FUNC:
				func(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero modulus\n");
				break;
			case '\n':
				printf("result: %.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100 		/* maximum depth of val stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* top: get the top of the stack without popping */
double top(void)
{
	if (sp > 0)
		return val[sp-1];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}

}

/* swap: swap the top two elements */
void swap(void)
{
	if (sp < 2)
		printf("error: less than 2 elements\n");
	else
	{
		int t = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = t;
	}
}

#include <ctype.h>

void func(char s[])
{
	double op2;

	if (0 == strcmp(s, "sin"))
		push(sin(pop()));
	else if (0 == strcmp(s, "cos"))
		push(cos(pop()));
	else if (0 == strcmp(s, "exp"))
		push(exp(pop()));
	else if (!strcmp(s, "pow"))
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("%s is not a supported function.\n", s);
}

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c, next;

	while (isblank(s[0] = c = getch()))
		;
	s[1] = '\0';

	i = 0;

	if (isalpha(c))
	{
		while (isalpha(s[++i] = c = getch()))
			;
		if (c != EOF)
			ungetch(c);
		s[i] = '\0';
		return FUNC;	/* function call */
	}

	if (!isdigit(c) && c != '.' && c != '-')	/* not a number but may contain a unary minus */
		return c;		/* operator exclude minus */	

	if (c == '-')
	{
		next = getch();
		if (!isdigit(next) && next != '.')
		{
			ungetch(next);
			return c;	/* minus operator */
		}
		c = next;
	}
	else
		c = getch();

	while (isdigit(s[++i] = c))
		c = getch();
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;		/* number */
}

#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void)			/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}