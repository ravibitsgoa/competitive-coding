#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000 /*size of integers array*/
#define PRIMES 700000 /*size of primes array*/
int *primes, *numbers;
int bSearch(int n, int start, int end)
{ printf("%d",n);
  int middle = (start+end)/2;
  if (start>end)
    return -1;
  if(n==primes[middle])
    return middle;
  if (n>primes[middle] && n<=primes[middle+1])
    return middle+1;
  if (n>primes[middle])
    return bSearch(n,middle+1, end);
  else
    return bSearch(n,start,middle-1);
}

int main()
{ int i,j;
  //int count = 0;
  primes = (int*)malloc(sizeof(int)*PRIMES);
  numbers = (int*)malloc(sizeof(int)*LIMIT);
  /*fill the array with natural numbers*/
  for (i=0;i<LIMIT;i++)
  { numbers[i]=i+2;
  }
  /*sieve the non-primes*/
  for (i=0;i<LIMIT;i++)
  { if (numbers[i]!=-1)
    { for (j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
        numbers[j]=-1;
    }
  }
  /*transfer the primes to their own array*/
  j = 0;
  for (i=0;i<LIMIT&&j<PRIMES;i++)
    if (numbers[i]!=-1)
      primes[j++] = numbers[i];
  int t;
  scanf("%d",&t);
  while(t--)
  { int a, b;
    scanf("%d %d",&a,&b);
    int x=bSearch(a, 0, LIMIT);
    printf("%d\n", x);
  }
  //printf("count=%dn",count);

return 0;
}
