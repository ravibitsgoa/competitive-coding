#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while (t--)
  { int n, a, b, sum=0, ans=0;
    cin>>n>>a>>b;
    while(a){sum+=a%2; a/=2;}
    while(b){sum+=b%2; b/=2;}
    if(sum < n+1)
    { while(sum)
      { ans+=1<<(n-sum);
        sum--;
      }
    }
    else
    { ans=1<<n; ans--; sum-=n;
      while(sum)
      { sum--;
        ans-=1<<sum;
      }
    }
    cout<<ans<<endl;
  }
return 0;

}
