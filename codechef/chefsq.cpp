#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int a, b;
        cin>>a;
        int s[a];
        for(int i=0; i<a; i++) cin>>s[i];
        cin>>b;
        int f[b];
        for(int i=0; i<b; i++) cin>>f[i];
        int j=0;
        for(int i=0; i<a; i++)
        {   while(f[j]==s[i])
            {   j++; i++;
            }
            if(j==b) {cout<<"Yes"<<endl; break;}
        }
        if(j!=b) cout<<"No"<<endl;
    }
    return 0;
}
