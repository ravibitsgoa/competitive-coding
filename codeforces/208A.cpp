#include<iostream>
#include<string>
using namespace std;
int main()
{   string s;
    bool flag=0;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {   if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {   i+=2;
            if(flag)
            {   cout<<' ';
            }
            flag=0;
        }
        else {cout<<s[i]; flag=1;}
    }
return 0;
}
