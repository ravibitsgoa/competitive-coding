#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LIMIT 50000 /*size of integers array*/
#define PRIMES 10000 /*size of primes array*/
#define gc getchar
#define pc(x) putchar(x);
int *primes, *numbers;

void scanint(long long int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
void writeInt (long long int n)
{
    long long int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int main()
{
  primes = (int*)malloc(sizeof(int)*PRIMES);  //This is an array of primes upto 10^6
  numbers = (int*)malloc(sizeof(int)*LIMIT);  //This stores all numbers upto 10^6.

  /*fill the array with natural numbers*/
  for (int i=1;i<LIMIT;i++)
  { numbers[i]=i;
  }
  numbers[1]=-1;//1 is not a prime.
  /*sieve the non-primes*/
  for(int i=2;i<LIMIT;i++)
  { if(numbers[i]!=-1)                    //This signifies that 'i' is a prime.
    { for(int j=2*i;j<LIMIT;j+=i)
      { numbers[j]=-1;
      }
    }
  }

  /*transfer the primes to their own array*/
  int j = 0;
  for(int i=2; i<LIMIT && j<PRIMES; i++)
    if (numbers[i]!=-1)
      primes[j++] = numbers[i];
  const int numprime=j;
  //haash! sieve nu kaam patyu. have primes no array taiyaar chhe.
  long long int t;
  scanint(&t);
  while(t--)
  { long long int m, n;
    scanint(&m);
    scanint(&n);
    for(long long int i=m; i<=n; i++)
    { if(i<LIMIT && numbers[i]!=-1)
      { writeInt(i);
        pc('\n');
      }
      else if(i>=LIMIT)
      { int primechhe=1;
        for(int j=0; j<numprime && primes[j]<=sqrt(i); j++)
        { if(i%primes[j]==0)
          { primechhe=0;
            break;
          }
        }
        if(primechhe==1)
        { writeInt(i);
          pc('\n');
        }
      }
    }
    pc('\n');
  }
return 0;
}
