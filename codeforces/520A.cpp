#include<iostream>
using namespace std;
int main()
{   int n, fre[26]={0}, i;
    cin>>n;
    string s;
    cin>>s;
    for(i=0; i<s.length(); i++)
    {   if(s[i]<97)
        fre[s[i]-65]++;
        else fre[s[i]-97]++;
    }
    for(i=0; i<26; i++)
    {   if(fre[i]==0)
        {cout<<"NO"; break;}
    }
    if(i==26)
    {   cout<<"YES";
    }
    return 0;
}
