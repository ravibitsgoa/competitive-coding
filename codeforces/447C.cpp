#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int a[n], sol[n][2]={0};
  bool ch[n]={0};
  for(int i=0; i<n; i++)
    cin>>a[i];
  sol[0][0]=sol[0][1]=1;
  if(a[0]==a[1])
  { a[0]--;
    ch[0]=1;
  }
  int ans=1;
  for(int i=1; i<n; i++)
  { if(a[i]>a[i-1])
    { sol[i][0]=sol[i-1][0]+1;
    }
    else
    { a[i]=a[i-1]+1;
      ch[i]=1;
      sol[i][1]=sol[i-1][0]+1;
      sol[i][0]=0;
    }
    ans=max(ans, max(sol[i][0], sol[i][1]));
    //cout<<ans;
  }
  cout<<ans;
  return 0;
}
