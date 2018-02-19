#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

#define LIMIT 1000000 /*size of integers array*/
#define PRIMES  80000 /*size of primes array*/

int main()
{   int i,j;
    int *primes,*numbers;
    int count = 0;

    primes = (int*)malloc(sizeof(int)*PRIMES);
    numbers = (int*)malloc(sizeof(int)*LIMIT);

    /*fill the array with natural numbers*/
    for (i=0;i<LIMIT;i++)
    {  numbers[i]=i+2;
    }

    /*sieve the non-primes*/
    for (i=0;i<LIMIT;i++)
    {   if (numbers[i]!=-1)
        { for (j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
            numbers[j]=-1;
        }
    }

    /*transfer the primes to their own array*/
    j = 0;
    for (i=0;i<LIMIT&&j<PRIMES;i++)
        if (numbers[i]!=-1)
            primes[j++] = numbers[i];

//NOW comes the main part.
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  { int n, inp;
    long long int pro=1;
    int freq[PRIMES]={0};
    cin>>n;
    while(n--)
    { cin>>inp;
      for(i=0; i<PRIMES && inp>1 && primes[i]!=0; i++)
      { while(inp>1 && inp%primes[i]==0)
        { freq[i]++;
          inp/=primes[i];
        }
      }
      //if(inp>1 && i>=170)
        //pro*=2;
    }
    for(int i=0; i<PRIMES; i++)
    { pro*=(freq[i]+1);
    }
    cout<<pro<<endl;
  }
return 0;
}
