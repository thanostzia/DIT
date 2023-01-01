/* Using an infinite sum series to compute π. The do_while loop computes π/4 */
/* Average computation time: ~12sec */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979320

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
        i += 2;
    } 
    while (current > 1.0e-10);
    /* The sum computes π/4 */

    sum *= 4;   /* sum = π */

    divergence = PI - sum;
    if (divergence < 0) divergence *= -1;

    printf("π (computed)   =%19.16lf\nπ (real value) = %.16lf\nDivergence: %23.16lf\n%ld iterations were performed for the computation.\n", sum, PI, divergence, --count);

    return 0;
}