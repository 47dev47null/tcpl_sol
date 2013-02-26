/* Exercise 7-3
 * Revise minprintf to handle more of the other facilities of printf. 
 */

/* TODO
 * Support precision and width
 */

#include <stdarg.h>
#include <stdio.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
            case 'd': case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'c':
                ival = va_arg(ap, char);
                putchar(ival);
                break;
            case 'u':
                uval = va_arg(ap, unsigned int);
                printf("%u", uval);
                break;
            case 'o':
                uval = va_arg(ap, unsigned int);
                printf("%o", uval);
                break;
            case 'x':
                uval = va_arg(ap, unsigned int);
                printf("%x", uval);
                break;
            case 'X':
                uval = va_arg(ap, unsigned int);
                printf("%X", uval);
                break;
            case 'e':
                dval = va_arg(ap, double);
                printf("%e", dval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'g':
                dval = va_arg(ap, double);
                printf("%g", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf("%s", sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

int main(void)
{
    minprintf("%d\n%f\n%s\n", 32, 3.14, "hello");

    return 0;
}
