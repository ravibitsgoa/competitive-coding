#include<iostream>
#include<map>
using namespace std;
int in(string s)
{   int ans=0;
    for(int i=0; s[i]!=0; i++)
    {   for(int j=i; s[j]!=0; j++)
        {   if(s[j]<s[i]) ans++;
        }
    }
    return ans;
}
int main()
{   int n, m;
    map<int, string> a;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {   string x;
        cin>>x;
        if(a[in(x)]=="")
            a[in(x)]=x;
        else
            a[in(x)]=a[in(x)]+"\n"+x;
    }
    for(map<int, string>:: iterator i=a.begin(); i!=a.end(); i++)
        cout<<(i->second)<<endl;
    return 0;
}
//Accepted.
