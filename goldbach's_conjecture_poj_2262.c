#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/

int main()
{   int i, j, *numbers;

    numbers = malloc(sizeof(int)*LIMIT);

    /*fill the array with natural numbers*/
    for (i=0;i<LIMIT;i++)
    {   numbers[i]=i+2;
    }

    /*sieve the non-primes*/
    for (i=0;i<LIMIT;i++)
    {   if (numbers[i]!=-1)
        {   for (j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
                numbers[j]=-1;
        }
    }
    int n;
    while(scanf("%d",&n) && n>0)
    {   for(i=3; i<=n/2; i++)
        {   if(numbers[i]!=-1 && numbers[n-i-2]!=-1)
            {   printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }
        if(i>n/2)
        {   printf("Goldbach's conjecture is wrong.\n");
        }
    }
return 0;
}
