/* Using an infinite sum series to compute ln(2). The do_while loop computes ln(2). */
/* Average computation time: ~25sec */
/* The same code format is followed in all .c files that compute the infinite series. */

#include <stdio.h>

#define LN2 0.6931471805599453

int main()
{
    double sum, current, divergence;
    long i, count;

    i = 1;
    count = 1;
    sum = 0.0;
    do
    {
        current = 1.0/i;
        if (count++ % 2) sum += current;
        else             sum -= current;
        i++;
    } 
    while (current > 1.0e-10);
    /* The sum computes ln(2) */

    divergence = LN2 - sum;

    printf("ln(2) (computed)   = %18.16lf\nln(2) (real value) = %.16lf\nDivergence: %27.16lf\n%ld iterations were performed for computation.\n", sum, LN2, divergence, i);

    return 0;
}