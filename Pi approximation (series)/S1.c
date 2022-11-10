/*
  Approximation of pi using 16 decimal digits.
  The sum calculates (π^2)/12
  π: 3.1415926535897932...
  π using S1.c: 3.1415926535897278
  Deviance: 3 decimal digits.
*/

#include <stdio.h>            
#include <math.h>                     

int main()
{ 
    int j;
    long i;
    double sum, current, pi;

    i = 1;   
    j = 1;                            
    sum = 0.0;

    do {
      current = 1/(((double) i)*((double) i));         
      sum = sum+current*j;                    
      i++;
      j *= -1;                                            
    } while (current > 1.0e-15);
    pi = sqrt(12*sum);                    
    printf("Summed %8ld terms, pi is %10.16f\n", i-1, pi);
}
    