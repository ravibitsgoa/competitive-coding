#include<vector>
#include<iostream>
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
    vector<string> inp;
    vector<int> inv;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {   string x;
        cin>>x;
        inp.push_back(x);
        inv.push_back(in(x));
    }
    for(int i=0; i<m; i++)
    {   int mini=0;
        while(inv[mini]==0) mini++;
        for(int j=0; j<m; j++)
        {   if(inv[j]<inv[mini] && inv[j]!=0) {mini=j;}
        }
        for(int j=0; j<m; j++)
        {   if(inv[j]==inv[mini] && j!=mini) {cout<<inp[mini]<<endl; inv[mini]=0; mini=j;}
        }
        cout<<inp[mini]<<endl;
        inv[mini]=0;
    }
    return 0;
}
