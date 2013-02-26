/* Exercise 7-4
 * Write a private version of scanf analogous to minprintf from the previous 
 * section.
 */

/* TODO
 * Support precision and width
 */

#include <stdarg.h>
#include <stdio.h>

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;
    unsigned *uval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%' && *p == getchar())
            continue;

        if (*p != '%')
        {
            fprintf(stderr, "Illegal format");
            break;
        }

        switch (*++p)
        {
            case 'd': case 'i':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'c':
                ival = va_arg(ap, char *);
                *ival = getchar();
                break;
            case 'u':
                uval = va_arg(ap, unsigned int *);
                scanf("%u", uval);
                break;
            case 'o':
                uval = va_arg(ap, unsigned int *);
                scanf("%o", uval);
                break;
            case 'x':
                uval = va_arg(ap, unsigned int *);
                scanf("%x", uval);
                break;
            case 'X':
                uval = va_arg(ap, unsigned int *);
                scanf("%X", uval);
                break;
            case 'e':
                dval = va_arg(ap, double *);
                scanf("%e", dval);
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf("%f", dval);
                break;
            case 'g':
                dval = va_arg(ap, double *);
                scanf("%g", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            default:
                fprintf(stderr, "Illegal format in switch");
                break;
        }
    }
    va_end(ap);
}

int main(void)
{
    int day, month, year;

    minscanf("%d/%d/%d", &day, &month, &year);

    printf("%d %d %d\n", day, month, year);

    return 0;
}
