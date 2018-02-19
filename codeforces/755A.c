#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/
int *primes, *numbers;
int main()
{ int i,j;
  primes = malloc(sizeof(int)*PRIMES);
  numbers = malloc(sizeof(int)*LIMIT);

  /*fill the array with natural numbers*/
  for (i=0;i<LIMIT;i++)
  { numbers[i]=i;
  }

  /*sieve the non-primes*/
  for (i=2;i<LIMIT;i++)
  { if (numbers[i]!=-1)
    { for (j=2*i;j<LIMIT;j+=i)
        numbers[j]=-1;
    }
  }

  //NOw the main part starts.
  int n;
  scanf("%d",&n);
  for(i=1; i<=1000; i++)
  { if(numbers[n*i +1]==-1)
    { printf("%d",i);
      break;
    }
  }

return 0;
}
