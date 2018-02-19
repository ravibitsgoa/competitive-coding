#include <bits/stdc++.h>

#define LIMIT 100 /*size of integers array*/
#define PRIMES 100 /*size of primes array*/
int *primes, *numbers;
/*int bSearch(int n, int start, int end)
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
}*/

using namespace std;
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  //int i, j;
  //int count = 0;
  primes = (int*)malloc(sizeof(int)*PRIMES);
  numbers = (int*)malloc(sizeof(int)*LIMIT);
  /*fill the array with natural numbers*/
  for (int i=0;i<LIMIT;i++)
  { numbers[i]=i+2;
  }
  /*sieve the non-primes*/
  for (int i=0;i<LIMIT;i++)
  { if (numbers[i]!=-1)
    { for (int j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
        numbers[j]=-1;
    }
  }
  /*transfer the primes to their own array*/
  int j = 0;
  for (int i=0;i<LIMIT&&j<PRIMES;i++)
    if (numbers[i]!=-1)
      primes[j++] = numbers[i];
  const int numprime=j;
  //haash! sieve nu kaam patyu. have primes no array taiyaar chhe.
  long long int *score=new long long int[LIMIT], *mxfact= new long long int [LIMIT];
  score[1]=1; mxfact[1]=0;
  score[2]=2; mxfact[2]=1;
  score[3]=2; mxfact[3]=1;
  for(int i=4; i<LIMIT; i++)
  { int j, k=0;
    int n=i;
    int factors[LIMIT];
    for(j=0; primes[j]<=n; j++)
    { int temp=0;
      while(primes[j]!=0 && n%primes[j]==0)
      { n/=primes[j]; temp++;
      }
      //factors.push_back(temp);
      factors[k]=temp; k++;
      if(score[mxfact[i]]<score[primes[j]] && temp!=0)
        mxfact[i]=primes[j]; //primes[j] has max number of divisors.
      if(score[mxfact[i]]<score[i/primes[j]] && temp!=0)
        mxfact[i]=i/primes[j];
    }
    long long int fact=1;
    for(int j=0; j<k; j++)
      fact*=factors[j]+1;
    score[i]=fact;
    if(mxfact[i]==0)
      mxfact[i]=1;
  }
  long long int A, B, ans=0;
  cin>>A>>B;
  for(int i=A; i<=B; i++)
  { ans--;            //because the root node 'i' is not having any parent.
    for(int j=i; j>0;)
    { ans+=score[j];
      j=mxfact[j];
      //cout<<j;
    }
    cout<<i<<' '<<ans<<endl;
    //cout<<i<<' '<<score[i]<<' '<<ans<<endl;
  }
  cout<<ans;
return 0;
}
