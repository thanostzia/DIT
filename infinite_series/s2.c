/* Using an infinite sum series to compute ln(2). The do_while loop computes ln(2). */
/* Average computation time: ~25sec */

#include <stdio.h>
#include <math.h>

#define LN2 0.6931471805599453

int main()
{
    double sum, current, divergence;
    long i;

    i = 1;
    sum = 0.0;
    do
    {
        current = 1/((double)(i));
        if (i++%2)  sum += current;
        else        sum -= current;
    } 
    while (current > 1.0e-10);
    /* The sum computes ln(2) */

    divergence = LN2 - sum;

    printf("ln(2) (computed)   = %.16lf\nln(2) (real value) = %.16lf\nDivergence:          %.16lf.\n%ld iterations were performed for computation.\n", sum, LN2, divergence, i);

    return 0;
}