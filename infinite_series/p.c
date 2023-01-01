/* Using an infinite sum series to compute π. The do_while loop computes π/2 */
/* Average computation time: ~0.006sec */

#include <stdio.h>

#define PI 3.1415926535897932

int main()
{
    double sum, current, divergence;
    long i, j, count;

    i = 2;
    j = 1;
    count = 1;
    sum = 1.0;
    do
    {
        current = (1.0*i) / j;
        sum *= current;
        if (count++ % 2) j += 2;
        else           i += 2;
    } 
    while (count <= 1.0e+10);
    /* The sum computes π/2 */

    sum *= 2;         /* sum = π */

    divergence = PI - sum;
    if (divergence < 0) divergence *= -1;

    printf("π (computed)   =%19.16lf\nπ (real value) = %.16lf\nDivergence: %23.16lf\n%ld iterations were performed for the computation.\n", sum, PI, divergence, --count);

    return 0;
}