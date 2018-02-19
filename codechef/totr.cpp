#include<iostream>
using namespace std;
int main()
{ int t;
  string s;
  cin>>t>>s;
  while(t--)
  { string x;
    cin>>x;
    for(int i=0; i<x.length(); i++)
    { if(x[i]>96 && x[i]<(97+26))
        cout<<s[x[i]-97];
      else if(x[i]>64 && x[i]<(65+26))
        cout<<(char)(s[x[i]-65]-32);
      else if(x[i]=='_')
        cout<<' ';
      else cout<<x[i];
    }
    cout<<endl;
  }
return 0;
}
