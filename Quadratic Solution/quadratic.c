/* Solving the quadratic equation for 3 random numbers a, b, c in range [0,1]. Approximation: 3 decimal points. Computing only for real solutions. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    float a,b,c,D,x1,x2;
    srand(time(0));
    a = rand() / ((double) RAND_MAX);
    b = rand() / ((double) RAND_MAX);
    c = rand() / ((double) RAND_MAX);
    D = b*b-4*a*c;
    printf("\n");
    if (D < 0)
    {
        printf("For a = %.3f, b = %.3f, c = %.3f, the quadratic has no real solutions.\n", a, b, c);
    }
    else if (D == 0)
    {
        x1 = (-1)*b/(2*a);
        printf("For a = %.3f, b = %.3f, c = %.3f, the quadratic has a double root: x = %.3f\n", a, b, c, x1);
    }
    else
    {
        x1 = ((-1)*b-sqrt(D))/(2*a);
        x2 = ((-1)*b+sqrt(D))/(2*a);
        printf("For a = %.3f, b = %.3f, c = %.3f, the quadratic has a two distinct roots: x1 = %.3f and x2 = %.3f\n", a, b, c, x1, x2);
    }
    return 0;
}