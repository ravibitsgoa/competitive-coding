#include<cassert>
#include<iostream>
using namespace std;

int g[26]={0};
string inp;
string x;

bool correct(int inp0, int inpl, int x0, int xl)
{ //cout<<inp0<<' '<<inpl<<' '<<x0<<' '<<xl<<endl;
  int i;
  assert((inpl-inp0)==(xl-x0));
  for(i=inp0; i<inpl; i++)
  { if(inp[i]!='?' && x[i+x0-inp0]!=inp[i])
      return 0;
    if(inp[i]=='?' && !g[x[i+x0-inp0]-'a'])
      return 0;
  }
  //cout<<inp0<<' '<<inpl<<' '<<x0<<' '<<xl<<endl;
  return 1;
}

int main()
{ string good;
  cin>>good;

  for(int i=0; i<good.length(); i++)
    g[good[i]-'a']=1;

  cin>>inp;

  int n;
  cin>>n;

  int star=0, index=0;
  for(int i=0; i<inp.length(); i++)
  { if(inp[i]=='*')
    { star=1;
      index=i;
    }
  }
  //cout<<index;
  while(n--)
  { cin>>x;
    if(!star && x.length() != inp.length())
    { cout<<"NO";
    }
    else if(!star)
    { if(correct(0, inp.length(), 0, x.length()))
        cout<<"YES";
      else
        cout<<"NO";
    }
    else if(x.length() < inp.length()-1)
      cout<<"NO";
    else if( correct (0, index, 0, index) && correct(index+1, inp.length(), x.length()-inp.length()+index+1, x.length()) )
    { int i;
      //cout<<index;
      for(i=index; i<=(x.length()-inp.length()+index); i++)
      { if(g[x[i]-'a'])
          break;
      }
      if(i>=x.length()-inp.length()+index+1)
        cout<<"YES";
      else
        cout<<"NO";
    }
    else
      cout<<"NO";
    cout<<'\n';
  }
  return 0;
}
