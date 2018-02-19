#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int s,d;//s is no. of states, d is no. of districts.
    cin>>s>>d;
    int inp[s*d], sum[s*d];
    cin>>inp[0];
    sum[0]=inp[0];
    for(int i=1; i<(s*d); i++)
    { cin>>inp[i];
      sum[i]=sum[i-1]+inp[i];
    }
    int ans=0;
    if(d==1)
    { cout<<(sum[(s*d)-1]>((s*d)/2))<<endl;
      continue;
    }
    int count=0;

    for(int j=0; j<(s*d); j+=d)
    { count+=(inp[j]+sum[(j+d-1)]-sum[j])>(d/2);
    }
    if(count>s/2)
      ans++;
    for(int i=1; i<d && ans==0; i++)
    { count=0;
      for(int j=i; j<((s*d)+i-d); j+=d)
      { count+=(inp[j]+sum[(j+d-1)]-sum[j])>(int)(d/2);
        //cout<<count;
      }
      count+=(sum[i-1]+sum[(s*d)-1]-sum[(s*d)+i-d-1])>(int)(d/2);
      //cout<<count<<endl;
      if(count>s/2)
      { ans++;
        break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
