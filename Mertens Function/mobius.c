#include <stdio.h>

//Range: [1, 19]

int n,k,j,prime,counter,ET;

int main()
{
    printf("μ(1) = 1");
    for (n=2; n<=19; n++)                                                                               //For each number "n" in Mobius function
    {
        counter=0;
        ET=1;
        for (k=2; k*k<=n; k++)                                                                          //For each number "k" that can divide n
        {
            prime=1;

            for (j=2; j*j<=k; j++)                                                                      //Check if "k" is prime
            {
                if (k%j==0)
                {
                    prime=0;
                }
            }

            if ( (n%k==0) && (prime==1) )                                                                   //If k divides n and k is prime
            {
                counter+=1;
            }
        }
        
    }

}
