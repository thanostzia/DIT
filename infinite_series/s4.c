/* Using an infinite sum series to compute 1/2. The do_while loop computes 1/2 */
/* Average computation time: ~0.4sec */

#include <stdio.h>

#define ONEHALF 0.5000000000000000

int main()
{
    double sum, current, divergence;
    long i, count;

    i = 1;
    count = 1;
    sum = 0.0;
    do
    {
        current = 1.0/(i*(i+2));
        sum += current;
        i += 2;
        count++;
    } 
    while (current > 1.0e-17);
    /* The sum computes 1/2 */

    divergence = ONEHALF - sum;

    printf("1/2 (computed)   =%19.16lf\n1/2 (real value) = %.16lf\nDivergence: %25.16lf\n%ld iterations were performed for the computation.\n", sum, ONEHALF, divergence, --count);

    return 0;
}