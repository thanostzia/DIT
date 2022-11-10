#include <stdio.h>

int main()
{
    int n, temp, factor;
    for (n=2; n<=20; n++)
    {
        printf("Prime factors of %d are:", n);
        temp = n;
        factor = 2;
        while (factor * factor <= temp)
        {
            while (temp % factor == 0)
            {
                printf(" %d", factor);
                temp /= factor;
            }
            if (factor ==2)
            {
                factor = 3;            
            }
            else if (factor == 3)
            {
                factor = 5;
            }
            else if (factor % 6 == 5)
            {
                factor += 2;
            }
            else
            {
                factor += 4;
            }            
        }
        if (temp != 1)
        {
            printf(" %d", temp);
        }
        printf("\n"); 
    }
}