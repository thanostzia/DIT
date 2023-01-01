/* Using an infinite sum series to compute pi. The do_while loop computes (π^2)/12 */
/* Average computation time: ~0.08sec */

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932

int main()
{
    double sum, current, divergence;
    long i;

    i = 1;
    sum = 0.0;
    do
    {
        current = 1/((double)(i*i));
        if (i++%2)  sum += current;
        else        sum -= current;
    } 
    while (current > 1.0e-15);
    /* The sum computes (π^2)/12 */

    sum *= 12;   /* sum = π^2 */
    sum = sqrt(sum);  /* sum = π */

    divergence = PI - sum;

    printf("π (computed)   = %.16lf\nπ (real value) = %.16lf\nDivergence:      %.16lf.\n%ld iterations were performed for the computation.\n", sum, PI, divergence, i);

    return 0;
}