#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   string s;
        cin>>s;
        int i;
        for(i=0; i<s.length()-1; i++)
        {   if(s[i]==s[i+2] && s[i]!=s[i+1])
            {cout<<"Good"<<endl; break;}
        }
        if(i==s.length()-1){cout<<"Bad"<<endl;}
    }
    return 0;
}
