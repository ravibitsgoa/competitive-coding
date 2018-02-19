#include<vector>
#include<iostream>
using namespace std;
int main()
{ int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  long long factor[1005]={0}, bigfactor[1005]={0};
  int good[1005]={0};
  factor[1]=0;
  for(int i=2; i<1005; i++)
  { int temp=i;
    long long mul=1;
    for(int j=0; primes[j-1]!=37 && temp>=primes[j]; j++)
    { if(temp%primes[j]==0)
        factor[i] |= mul;
      if(temp % (primes[j]*primes[j]) == 0)
        good[i]=1;
      while(temp%primes[j]==0)
        temp/=primes[j];

      mul<<=1;
    }
    if(temp>1)
      bigfactor[i]=temp;
  }

  int T;
  cin>>T;
  while(T--)
  { int N;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
      cin>>A[i];
    long long ans=0;
    long long gunakar_na_avayavo=0, gunakar_na_mota_avayavo[1005]={0};
    long long sz=0, parts=0;
    int j=0, i=0;
    for(i=0; i<N; i++)
    { if(A[i]!=1 && ((good[A[i]]) || (factor[A[i]] & gunakar_na_avayavo) || (bigfactor[A[i]]>1 &&gunakar_na_mota_avayavo[bigfactor[A[i]]])))
      { sz=i-j;
        ans += sz*(sz+1)/2;

        if(good[A[i]])
        { j=i+1;
          gunakar_na_avayavo=0;
          for(int k=0; k<1005; k++) gunakar_na_mota_avayavo[k]=0;
        }
        else
        { for(; j<i; j++)
          { gunakar_na_avayavo^=factor[A[j]];
            if(bigfactor[A[j]]>1)
              gunakar_na_mota_avayavo[bigfactor[A[j]]]=0;
            if( (factor[A[i]] & factor[A[j]]) || (bigfactor[A[i]]>1 && bigfactor[A[j]]>1 && bigfactor[A[i]]==bigfactor[A[j]]) )
              break;
          }

          j++;
          gunakar_na_avayavo|=factor[A[i]];
          if(bigfactor[A[i]]>1)
            gunakar_na_mota_avayavo[bigfactor[A[i]]]=1;
        }

        sz=i-j;
        ans -= sz*(sz+1)/2;
      }
      else
      { gunakar_na_avayavo|=factor[A[i]];
        if(bigfactor[A[i]]>1)
          gunakar_na_mota_avayavo[bigfactor[A[i]]]=1;
      }
    }

    if(!good[A[i-1]])
    { sz=i-j;
      ans += sz*(sz+1)/2;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
