#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int a[]={0,1,2,3,4,5}, g[7][7]={0};
  int ans=0, currenthappiness=0;
  for(int i=1; i<=5; i++)
  { for(int j=1; j<=5; j++)
      cin>>g[i][j];
  }
  do
  { currenthappiness=0;
    for(int start=1; start<5; start++)
    { for(int j=start; j<5; j+=2)
      { currenthappiness+=g[a[j]][a[j+1]]+g[a[j+1]][a[j]];
      }
    }
    ans=max(ans, currenthappiness);
  }while(next_permutation(a+1, a+6));
  cout<<ans;
return 0;
}
