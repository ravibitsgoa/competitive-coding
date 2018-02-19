#include <bits/stdc++.h>

#define LIMIT 1000000 /*size of integers array*/
#define PRIMES 100000 /*size of primes array*/
int *primes, *numbers;
int primepowersofk[100005][100];
int numberofprimefactors[100005]={0};
unsigned long long int totaldivofk[100005];
unsigned long long int number[100005];

using namespace std;
bool comp(int i, int j) { return i > j; }

int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  primes = (int*)malloc(sizeof(int)*PRIMES);  //This is an array of primes upto 10^6
  numbers = (int*)malloc(sizeof(int)*LIMIT);  //This stores all numbers upto 10^6.

  /*fill the array with natural numbers*/
  for (int i=2;i<LIMIT;i++)
  { numbers[i]=i;
  }
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

  unsigned long long int A, B, ans=0;
  cin>>A>>B;

  for(int i=0; i<B-A+5; i++)
  { totaldivofk[i]=1;
    number[i]=i+A;
  }
  for(j=0; j<numprime; j++)
  { for(long long int k=A - (A%primes[j]); k<=B; k+=primes[j])
    { //cout<<k<<endl;
      if(k>=A)//&& number[k-A]%primes[j]==0)
      { //cout<<k<<' ';
        int temp=0;     //Here, too, temp does the same job.
        while(number[k-A]%primes[j]==0)
        { temp++;
          number[k-A]/=primes[j];
        }
        primepowersofk[k-A][numberofprimefactors[k-A]++]=temp+1;
        totaldivofk[k-A]*=temp+1;
        //cout<<k<<' '<<primes[j]<<endl;
      }
    }
  }
  for(long long int i=A; i<=B; i++)
  { //for(int j=0; j<=numberofprimefactors[i-A]; j++)
      //cout<<primepowersofk[i-A][j]<<' ';
    //cout<<endl;
    if(i==1)
      continue;
    ans--;
    if(number[i-A]!=1)
    { primepowersofk[i-A][numberofprimefactors[i-A]++]=1+1;//i has a big prime factor.
      totaldivofk[i-A]*=2;
    }
    sort(primepowersofk[i-A], primepowersofk[i-A]+numberofprimefactors[i-A], comp);
    while(primepowersofk[i-A][0]>0)//continues until we have at least 1 prime power.
    { //for(int j=0; j<=numberofprimefactors[i-A]; j++)
        //cout<<primepowersofk[i-A][j]<<' ';
      //cout<<endl;
      //The biggest frequency will be the foremost element.
      ans+=totaldivofk[i-A];
      //cout<<ans;
      totaldivofk[i-A]/=primepowersofk[i-A][0];
      primepowersofk[i-A][0]--;    //e.g. array becomes 3,2,2 -> 2,2,2 and product becomes 3*2*2 -> 2*2*2 after next line.
      totaldivofk[i-A]*=primepowersofk[i-A][0];// Now it stores the product of the elements of the array.
      sort(primepowersofk[i-A], primepowersofk[i-A]+numberofprimefactors[i-A], comp);
    }
    //cout<<i<<' '<<ans<<endl;
  }

  cout<<ans;
return 0;
}
