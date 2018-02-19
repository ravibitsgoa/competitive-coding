#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int, vector<int> > tree;
int hei(int head)
{ if(tree[head].size()==0)
    return 1;
  else if(tree[head].size()==1)
  { return 1+hei(tree[head][0]);
  }
  else
    return 1+max(hei(tree[head][0]), hei(tree[head][1]));
}
int main()
{ int n, x, head;
  cin>>n;
  for(int i=0; i<n; i++)
  { cin>>x;
    if(x==-1)
      head=i;
    if(x!=-1)
    { tree[x].push_back(i);
    }
  }
  cout<<hei(head);
return 0;
}
