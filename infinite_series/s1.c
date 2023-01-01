/* Using an infinite sum series to compute pi. The do_while loop computes (π^2)/12 */

#include <stdio.h>
#include <math.h>

int main()
{
    double sum, current;
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
    printf("π = %.16lf\n%ld iterations were performed for computation.\n", sum, i);

    return 0;
}