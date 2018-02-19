#include<iostream>
using namespace std;
int main()
{ int n=1;
  while(n)
  { cin>>n;
    if(n==0) break;
    int inp[n+1], i;
    for(i=1; i<=n; i++)
      cin>>inp[i];
    for(i=1; i<=n; i++)
    { if(inp[i]==i || inp[inp[i]]==i) {}
      else {cout<<"not ambiguous"<<endl; break;}
    }
    if(i==n+1) cout<<"ambiguous"<<endl;
  }
return 0;
}
