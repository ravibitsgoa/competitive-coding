#include<iostream>
#include<string>
using namespace std;
int ishero(string x)
{ int l=x.length();
  if(x[l-3]=='m' && x[l-2]=='a' && x[l-1]=='n')
    return 1;
  else
    return 0;
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, h=1, v=1;
    cin>>n;
    string name;
    int flag=0;
    while(n--)
    { cin>>name;
      if(ishero(name))
        h++;
      else
        v++;
      if(h==v+2 && flag==0)
        flag=1;
      if(v==h+3 && flag==0)
        flag=2;
    }
    if(flag==1)
      cout<<"superheroes";
    else if(flag==2)
      cout<<"villains";
    else
      cout<<"draw";
    cout<<endl;
  }
return 0;
}
