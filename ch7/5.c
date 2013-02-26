/* Exercise 7-5
 * Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do
 * the input and number conversion.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

void push(double);
double pop(void);

int main(void)
{
    char cmd[MAXLINE];
    char type;
    double op;
    char *s;

    s = cmd;
    if (fgets(s, MAXLINE, stdin) == NULL)
    {
        fprintf(stderr, "Unknown command");
        return 1;
    }

    while (1)
    {
        while (isblank(*s))
            s++;    /* remove all blank characters */

        if (sscanf(s, "%lf", &op) == 1)
        {
            while (isdigit(*s))
                s++;
            if (*s == '.')
            {
                s++;
                while (isdigit(*s))
                    s++;
            }   /* advance the pointer next input */
            push(op);
        }
        else if (sscanf(s, "%c", &type) == 1)
        {
            if (type == '+' ||  type == '-' || type == '*' || type == '/' 
                    || type == '%' || type == '\n')
                s++;

            if (type == '\n')
            {
                printf("result: %.8g\n", pop());
                break;      /* exit while loop */
            }

            switch (type)
            {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() + pop());
                    break;
                case '-':
                    op = pop();
                    push(pop() - op);
                    break;
                case '/':
                    op = pop();
                    if (op == 0.0)
                    {
                        fprintf(stderr, "divide by zero");
                        return 1;
                    }
                    push(pop() / op);
                    break;
                default:
                    fprintf(stderr, "Illegal operator");
                    break;
            }
        }
        else break;
    }
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
