#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    string x;
    cin>>x;
    if(n>1)
    { if(x[0]=='1') {x[0]='2'; if(n>1) x[1]='2';}
      for(int i=1; i<n-1; i++)
      { if(x[i]=='1')
        { x[i-1]='2';
          if(x[i+1]=='0') x[i+1]='2';
        }
      }
      if(x[n-1]=='1') { x[n-1]='2'; if(n>2) x[n-2]='2';}
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {  if(x[i]=='0') ans++;
    }
    cout<<ans<<endl;
  }
return 0;
}
