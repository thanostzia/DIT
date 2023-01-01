/* Using an infinite sum series to compute π. The do_while loop computes (π^4)/90 */
/* Average computation time: ~0.006sec */

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932

int main()
{
    double sum, current, divergence;
    long count;

    count = 1;
    sum = 0.0;
    do
    {
        current = 1.0/(count*count*count*count++);
        sum += current;
    } 
    while (current > 1.0e-16);
    /* The sum computes (π^4)/90 */

    sum *= 90;         /* sum = π^4 */
    sum = sqrt(sum);   /* sum = π^2 */
    sum = sqrt(sum);   /* sum = π */

    divergence = PI - sum;

    printf("π (computed)   =%19.16lf\nπ (real value) = %.16lf\nDivergence: %23.16lf\n%ld iterations were performed for the computation.\n", sum, PI, divergence, --count);

    return 0;
}