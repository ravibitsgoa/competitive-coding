#include<iostream>
using namespace std;
int main()
{ int n, m, ans=0;
  cin>>n;
  int x, y, x1, y1, x2, y2;
  cin>>x1>>y1;
  n--;
  while(n--)
  { cin>>x>>y;
    y1=min(y1,y);
    x1=max(x1,x);
  }
  //cout<<y1<<endl;
  cin>>m;
  m--;
  cin>>x2>>y2;
  while(m--)
  { cin>>x>>y;
    x2=max(x2,x);
    y2=min(y2,y);
  }
  //cout<<x2<<endl;
  //if(x2>y1)  cout<<x2-y1;
  //else cout<<0;
  ans=max(ans,max(x2-y1,x1-y2));
  cout<<ans;
  return 0;
}
