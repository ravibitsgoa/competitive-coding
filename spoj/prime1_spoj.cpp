#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/

int main(){
    int i,j;

    int primes [PRIMES];
    int numbers [LIMIT];

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

    /*transfer the primes to their own array*/
    j = 0;
    /*for (i=0;i<LIMIT&&j<PRIMES;i++)
        if (numbers[i]!=-1)
            primes[j++] = numbers[i];
    */
    int testcase, n1, n2;
    scanf("%d",&testcase);
    while(testcase--)
    {   scanf("%d %d",&n1,&n2);
        for (i=n1;i<n2;i++)
        {   if (numbers[i]!=-1)
            printf("%d\n",i);
        }
        printf("\n");
    }
return 0;
}
