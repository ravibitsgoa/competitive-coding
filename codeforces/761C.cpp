#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin>>n>>m;
  string x;
  int codes[n][3];
  for(int i=0; i<n; i++)
  { cin>>x;
    codes[i][0]=codes[i][1]=codes[i][2]=-1;
    for(int j=0; j<m; j++)
    { if(x[j]>='1' && x[j]<='9')
        if(codes[i][0]==-1 )
          codes[i][0]=j;
        else if(codes[i][0]>m-j)
          codes[i][0]=m-j;
      if(x[j]>='a' && x[j]<='z')
        if(codes[i][1]==-1 )
          codes[i][1]=j;
        else if(codes[i][1]>m-j)
          codes[i][1]=m-j;
      if(x[j]=='#' || x[j]=='*' || x[j]=='&')
        if(codes[i][2]==-1 )
          codes[i][2]=j;
        else if(codes[i][2]>m-j)
          codes[i][2]=m-j;
    }
  } int a=codes[0][0], b=codes[0][1], c=codes[0][2];
  //cout<<a<<b<<c<<endl;
  for(int i=0; i<n; i++)
  { if((a<0 || a>codes[i][0]) && codes[i][0]>=0)
      a=codes[i][0];
    if((b<0 || b>codes[i][1])&& codes[i][1]>=0)
    {  b=codes[i][1];
      //cout<<i;
    }
    if((c<0 || c>codes[i][2])&& codes[i][2]>=0)
      c=codes[i][2];
  }
  cout<<a+b+c;//<<a<<b<<c;
  return 0;
}
