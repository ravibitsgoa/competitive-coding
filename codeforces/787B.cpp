#include<set>
#include<iostream>
using namespace std;
int main()
{ int n, m;
  cin>>n>>m;
  bool x=1;
  while(m--)
  { int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
    { cin>>arr[i];
    }
    set<int>inp(arr, arr+size);
    x=1;
    for(auto i=inp.begin(); i!=inp.end(); i++)
    { if(inp.find(-(*i))!=inp.end())
        x=0;
    }
    if(x)
    { cout<<"YES";
      break;
    }
  } 
  if(!x)
    cout<<"NO";
return 0;
}
