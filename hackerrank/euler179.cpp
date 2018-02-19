//This is a great example on how to find total number of factors fast.
//constraints: T<=10^6, each query K<=10^7.
#include <cstdio>
#define LIMIT 10000005
#define PRIMES 10000005
using namespace std;
int primes[PRIMES];
int numbers [LIMIT];
int divisors[LIMIT]={0}, sum[LIMIT]={0}, nmax=100;  

void fastscan(int &number)
{   register int c;
    number = 0;
    // extract current character from buffer
    c = getchar();
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main() 
{ int i, j;
  /*Prime sieving.*/
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
  for (i=0; i<LIMIT && j<PRIMES;i++)
  { if (numbers[i]!=-1)
    { primes[j++] = numbers[i];
      divisors[numbers[i]]=2;
    }
  } 
  /*divisors[i] containes number of the same of i. sum[i] = number of numbers in (1,i) satisfying divisors[n]==divisors[n+1]*/   
  divisors[1]=1;
  sum[0]=sum[1]=0;
  for(i=2; i<=nmax; i++)
  { if(!divisors[i])
    { for(j=0; j<PRIMES && primes[j]<=i; j++)
      { if(!(i%primes[j]))
        { int temp=i, temp2=1, count=0;
          while(temp%primes[j]==0)
          { temp/=primes[j];
            temp2*=primes[j];
            count++;
          }
          if(temp==1)
            divisors[i]=count+1;
          else
            divisors[i]=divisors[temp]*divisors[temp2];  
          break;
        }
      }
    }
    sum[i]=sum[i-1]+(divisors[i]==divisors[i-1]);
  }
  
  int t;
  fastscan(t);
  while(t--)
  { int k;
    fastscan(k);
    if(k<=nmax)
      printf("%d\n",sum[k]);
    else
    { for(i=nmax; i<=k+1; i++)
      { if(!divisors[i])
        { for(j=0; j<PRIMES && primes[j]<=i; j++)
          { if(!(i%primes[j]))
            { int temp=i, temp2=1, count=0;
              while(temp%primes[j]==0)
              { temp/=primes[j];
                temp2*=primes[j];
                count++;
              }
              if(temp==1)
                divisors[i]=count+1;
              else
                divisors[i]=divisors[temp]*divisors[temp2];  
              break;
            }
          }
        }
        sum[i]=sum[i-1]+(divisors[i]==divisors[i-1]);
      }
      nmax=k+1;
      printf("%d\n",sum[k]);
    }
  }
  return 0;
}

