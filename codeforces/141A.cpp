#include<string>
#include<iostream>
using namespace std;
int main()
{   string a, b, t;
    cin>>a>>b>>t;
    int i, fre[27]={0};//frequency distribution
    for(i=0; i<a.length(); i++)
    {   fre[a[i]-65]++;
    }
    for(i=0; i<b.length(); i++)
    {   fre[b[i]-65]++;
    }
    for(i=0; i<t.length(); i++)
    {   fre[t[i]-65]--;
    }
    for(i=0; i<27; i++)
    {   if(fre[i]!=0)
        {   cout<<"NO"<<endl; break;
        }
    }
    if(i==27){cout<<"YES";}
    return 0;
}
