#include<iostream>
using namespace std;
string l[2];
int fun(int curr)
{ int i, count=0;
  for(i=0; i<l[0].length(); i++)
  { //cout<<i<<' '<<count<<endl;
    if(i==l[0].length()-1 || l[curr][i+1]=='.'){}
    else if(l[!curr][i+1]=='.')
    { curr=!curr;
      count++;
    }
    else
    { return -1;
    }
  }
  if(i==l[0].length())
    return count;
  else
    return -1;
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { int curr=0;
    cin>>l[0]>>l[1];
    if(l[0][0]==l[1][0] && l[0][0]=='#')
    { cout<<"No"<<'\n';
      continue;
    }
    else if(l[0][0]=='.' && l[1][0]!='.')
      curr=0;
    else if(l[0][0]!='.' && l[1][0]=='.')
      curr=1;
    else
    { //cout<<"Hey";
      int a=fun(0);
      int b=fun(1);
      if(a!=-1 && b!=-1)
        cout<<"Yes"<<'\n'<<min(a,b)<<'\n';
      else if(a!=-1 && b==-1)
        cout<<"Yes"<<'\n'<<a<<'\n';
      else if(b!=-1 && a==-1)
        cout<<"Yes"<<'\n'<<b<<'\n';
      else
        cout<<"No"<<'\n';
      continue;
    }
    int a=fun(curr);
    if(a==-1)
      cout<<"No"<<'\n';
    else
      cout<<"Yes"<<'\n'<<a<<'\n';
  }
  return 0;
}
