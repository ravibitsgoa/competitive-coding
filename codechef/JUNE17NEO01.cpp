#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int T;
  cin>>T;
  while(T--)
  { int N;
    cin>>N;
    long long inp[N], allsum=0;
    for(int i=0; i<N; i++)
    { cin>>inp[i];
      allsum+=inp[i];
    }
    sort(inp, inp+N);
    long long positive=0;
    long long i, sum=0, ans=0;
    for(i=N-1; i>=0 && inp[i]>=0; i--)
    { if(inp[i]>=0)
      { positive++;
        sum+=inp[i];
      }
    }
    ans=sum*positive + (allsum-sum);
    for(; i>=0; i--)
    { sum+=inp[i];
      ans=max(ans, sum*(N-i)+ (allsum-sum));
    }
    cout<<ans<<'\n';
  }
return 0;
}
