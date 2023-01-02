/* Using an infinite sum series to compute π. The do_while loop computes (π-3)/4 */
/* Average computation time: ~0.007sec */

#include <stdio.h>

#define PI 3.1415926535897932

int main()
{
    double sum, current, divergence;
    long i, count;

    i = 2;
    count = 1;
    sum = 0.0;
    do
    {
        current = 1.0/(i*(i+1)*(i+2));
        if (count++ % 2) sum += current;
        else             sum -= current;
        i += 2;
    } 
    while (current > 1.0e-16);
    /* The sum computes (π-3)/4 */

    sum *= 4;   /* sum = π-3 */
    sum += 3;   /* sum = π */

    divergence = PI - sum;

    printf("π (computed)   =%19.16lf\nπ (real value) = %.16lf\nDivergence: %23.16lf\n%ld iterations were performed for the computation.\n", sum, PI, divergence, --count);

    return 0;
}