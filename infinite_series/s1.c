/* Using an infinite sum series to compute π. The do_while loop computes (π^2)/12 */
/* Average computation time: ~0.08sec */
/* The same code format is followed in all .c files that compute the infinite series. */

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932

int main()
{
    double sum, current, divergence;
    long i, count;

    i = 1;
    count = 1;
    sum = 0.0;
    do
    {
        current = 1.0/(i*i);
        if (count++ % 2) sum += current;
        else             sum -= current;
        i++;
    } 
    while (current > 1.0e-15);
    /* The sum computes (π^2)/12 */

    sum *= 12;   /* sum = π^2 */
    sum = sqrt(sum);  /* sum = π */

    divergence = PI - sum;
    if (divergence < 0) divergence *= -1;

    printf("π (computed)   =%19.16lf\nπ (real value) = %.16lf\nDivergence: %23.16lf\n%ld iterations were performed for the computation.\n", sum, PI, divergence, --count);

    return 0;
}