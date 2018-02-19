#include<iostream>
#include<vector>
using namespace std;
int main()
{ int n, m;
  cin>>n>>m;
  string sub, super;
  cin>>sub>>super;
  int ans=n, count=0;
  vector<int> answer, temp;
  for(int i=0; i<=m-n; i++)
  { count=0;
    temp.clear();
    for(int j=0; j<n; j++)
    { if(sub[j]!=super[i+j])
      { count++;
        temp.push_back(j+1);
      }
    }
    if(count<=ans)
    { ans=count;
      answer=temp;
    }
  }
  cout<<ans<<'\n';
  for(int i : answer)
    cout<<i<<' ';
  return 0;
}
