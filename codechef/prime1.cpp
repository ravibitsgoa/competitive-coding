#include<bits/stdc++.h>
#define LIMIT 50000 /*size of integers array*/
#define PRIMES 10000 /*size of primes array*/
int *primes, *numbers;

using namespace std;
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);

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
  int t;
  cin>>t;
  while(t--)
  { int m, n;
    cin>>m>>n;
    for(int i=m; i<=n; i++)
    { if(i<LIMIT && numbers[i]!=-1)
        cout<<i<<'\n';
      else if(i>=LIMIT)
      { bool primechhe=1;
        for(int j=0; j<numprime && primes[j]<=sqrt(i); j++)
        { if(i%primes[j]==0)
          { primechhe=0;
            break;
          }
        }
        if(primechhe==1)
          cout<<i<<'\n';
      }
    }
    cout<<'\n';
  }
return 0;
}
