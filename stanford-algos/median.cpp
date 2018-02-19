#include<iostream>
#include<algorithm>
#define SIZE 10000
using namespace std;
int main()
{ int inp[SIZE+1], ans=0;
  //cin>>inp[0];
  for(int i=1; i<=SIZE; i++)
  { cin>>inp[i];
    sort(inp+1, inp+i+1);
    //cout<<inp[i/2]<<' ';
    if(i==1)
      ans+=inp[1];
    else if(i>1 && i%2==0)
      ans+=inp[i/2];
    else
      ans+=inp[(i+1)/2];
    //cout<<ans;
    ans%=SIZE;
  }
  cout<<ans;
  return 0;
}
