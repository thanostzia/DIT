/* This program computes all values of the Mertens function in range [1, 10^MAXEXP+9]. */

#include <stdio.h>        /*Standard input-output library, used for the printf() function.*/
#define MAXEXP 8          /*Exponent for base 10*/

int main()
{
    int i, n, nexponent, kexponent, temp, factor, count, M, ZP, sum, term, perfect, abundant;
    nexponent = 1;        /*Initializing variable to compute 10^MAXEXP*/
    
    for (i = 1; i <= MAXEXP; i++)   /*Evaluating 10^MAXEXP*/
    {
        nexponent *= 10;
    }

    //NOTE 1: Mertens function M(n) = The sum from k=1 to n of μ(k), where μ(k) is the Mobius function for value k. 

    ZP = 0;                /*Initializing variables for zero points ( M(n) = 0 ),*/
    M = 0;                 /*the Mertens function*/ 
    kexponent = 10;        /*and the variable which evaluates the powers of 10.*/

    for (n = 1; n <= nexponent + 9; n++)      /*From NOTE 1 we see that M(n) = M(n-1) + μ(n), where μ(n) is the Mobius function for value n. Therefore, only one sum can be used (for loop)*/
    {        
        /*Evaluating Mertens function for each n in range [1, 10^MAXEXP +9]*/
        
        /* Checking if n is Square-Free*/
        if (n % 4 == 0 || n % 9 == 0)                               /*If 4=2*2 or 9=3*3 is a divisor of n, we already know n is not Square-Free. Checking done in order for faster computations.*/
        {                                                           /*With this if-case, we exclude a big portion of all natural numbers with divisors 4 and 9 (not at the same time)*/
            if (n >= kexponent - 9 && n <= kexponent + 9)           
            {                                                       /*Printing M(n) for all n in range [10^k-9, 10^k+9], for k = 1, 2, 3, ... , MAXEXP*/
                printf("M(%d) = %d\n", n, M);
                if (n == kexponent + 9)                             /*If n = 10^k+9 for each k != MAXEXP, print "..."*/
                {
                    if (nexponent != kexponent)
                    {
                        printf("..........\n");
                    }
                    else                                            /*If k = MAXEXP, then n = 10^MAXEXP+9. Therefore we have checked all numbers in range [1, 10^MAXEXP+9]*/
                    {
                        break;                                      /*break command used for faster computations*/
                    }
                    kexponent *= 10;                                /*Multiplying current 10^k by 10*/
                }
            }
            if (M == 0)    /*Counting Zero Points*/
            {
                ZP += 1;
            }
            continue;      /*Finished with non-Square-Free number, continuing for next value n*/
        }
        /*Finding number of prime factors of n, if n is Square-Free*/
        
        count = 0;         /*Variable used to count prime factors of n*/
        temp = n;          /*Using temp variable in order to use n for computations without altering the original value.*/
        if (temp % 2 == 0)          /*We have already checked if 4 and 9 are divisors of n, so we safely divide by 2 & 3 if needed*/
        {
            count++;
            temp /= 2;
        }
        if (temp % 3 == 0)
        {
            count++;
            temp /= 3;
        }
        factor = 5;                 /*Starting with next prime factor after 2 & 3, 5.*/
        while (factor * factor <= temp)                /*Checking factors until the square root of n, base on the fact that all divisors after sqrt(n) are equal to n / (Current divisor)*/
        {                
            if (temp % factor == 0)                    /*If n is divisible by prime, the prime is a factor*/
            {
                count++;
                temp /= factor;
                if (temp % factor == 0)                /*If n is divisible by the same prime, then it is not Square-Free.*/
                {
                    count = -2;                        /*Setting low value for "count" variable in order to avoid wrong computations with the if-cases on lines 89 and 93.*/
                    break;                             /*Stopping counting factors for non-SF number*/ 
                }
            }
            if (factor % 6 == 5)                     /*Based on the "Sieve of Eratosthenes" algorithm.*/
            {                                        
                factor += 2;                         /*if factor is the first number from the next "number couples", increase by 2 to reach it*/
            }                                             
            else
            {
                factor += 4;                         /*if it's the second number, increase by 4*/
            }
        }                                            /*example of couples: 11-13, 17-19...*/
        if (temp != 1)                /*If not all factors were found with previous computations, then the remaining factor is the last temp value.*/
        {
            count++;
        }
        if (count % 2 == 0 && count >= 0)            /*Based on μ(n) = 1 if n is Square-Free and the number of its prime factors is even*/
        {
            M += 1;
        }
        else if (count % 2 == 1 && count >= 0)       /*Based on μ(n) = -1 if n is Square-Free and the number of its prime factors is odd*/
        {
            M -= 1;
        }
        if (M == 0)                                  /*Counting Zero Points*/
        {
            ZP += 1;
        } 
        if (n >= kexponent - 9 && n <= kexponent + 9)
        {
            printf("M(%d) = %d\n", n, M);                 /*Printing M(n) for all n in range [10^k-9, 10^k+9], for k = 1, 2, 3, ... , MAXEXP*/
            if (n == kexponent + 9)
            {
                if (nexponent != kexponent)               /*If n = 10^k+9 for each k != MAXEXP, print "..."*/
                {
                    printf("..........\n");
                }
                else                                       /*If k = MAXEXP, then n = 10^MAXEXP+9. Therefore we have checked all numbers in range [1, 10^MAXEXP+9]*/
                {
                    break;                                 /*break command used for faster computations*/
                }
                kexponent *= 10;                           /*Multiplying current 10^k by 10*/
            }
            continue;
        }               
    }
    printf("\nFound %d zero points of the Mertens function\n\n", ZP);
    
    printf("Checking numbers in the range [2, %d]\n\n", 1000*ZP);
    perfect = 0;      /*Used to count number of perfct numbers in range [2, 1000*ZP]*/
    abundant = 0;     /*Used to count number of abundant numbers in range [2, 1000*ZP]*/
    for (n = 2; n <= 1000*ZP; n++)                 /*sum, term and the computations inside the for-loop are explained at line 175 (NOTE 2)*/
    {
        sum = 1;                                  /*Initializing sum with 1, since it will be computed as a product of terms.*/
        temp = n;
        factor = 2;
        while (factor * factor <= temp)
        {
            term = 1;

            while (temp % factor == 0)             /*If number is divisible by prime, the prime is a factor*/
            {
                term = factor * term + 1;          /*For number x = 1+x+x^2+...x^k:  term=term*x+1*/                                                                                                         
                temp /= factor;                    /*term = (1 + pi + pi^2 + pi^3 + ... + pi^ei)*/
            }
            sum *= term;                                            

            if (factor == 2)                       /*Checking for primes 2, 3, 5*/                                                                                   
            {
                factor = 3;
            }
            else if (factor == 3)
            {
                factor = 5;
            }
            else if (factor % 6 == 5)                /*Based on the "Sieve of Eratosthenes" algorithm.*/
            {                                        
                factor += 2;                         /*if factor is the first number from the next "number couples", increase by 2 to reach it*/
            }                                             
            else
            {
                factor += 4;                         /*if it's the second number, increase by 4*/
            }
        }                                            /*example of couples: 11-13, 17-19...*/
        if (temp != 1)                    /*If not all factors were found with previous computations, then the remaining factor is the last temp value.*/
        {
            sum *= (1 + temp);
        }
        if ( sum - n == n)                /*We check if a number is perfect, abundant or deficient by summing its divisors without n itself.*/
        {                                                          /*If s(n) = σ(n) - n, then: */
            printf("Found perfect number: %d\n", n);
            perfect++;                                             /*If s(n) = n, n is a perfect number*/
        }
        else if (sum - n > n)
        {
            abundant++;                                            /*If s(n) > n, n is an abundant number*/                                                 
        }
    }
    printf("\nFound %d deficient numbers\n", ZP*1000-(abundant+perfect+1));         /*For any range [a, b] abundant+deficient+perfect = b. We perform computations from a = 2, therefore we add +1. I do not use a variable for deficient numbrs to save memory space.*/
    printf("Found %d abundant numbers\n", abundant);
}

/* NOTE 2:
   Consider we have the prime factorization of n in the form:  n = p1^a1 * p2^a2 * ... * pk^ak, where pi is a prime factor of n and ai is the number of times pi divides n. (1 <= i <= k)

   if σ(n) is the function which computes the sum of all divisors of n (including n itself), then:
   σ(n) = term1 * term2 * term3 * ... * termk, 
   where termi = (1 + pi + pi^2 + pi^3 + ... + pi^ei) for each i in range [1, k].
*/
