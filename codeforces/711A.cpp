#include<iostream>
using namespace std;
int main()
{   int n, flag=1;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n && flag; i++)
    {   if(s[i][0]=='O' && s[i][1]=='O')
        {   s[i][0]='+'; s[i][1]='+';
            flag=0;
        }
        else if(s[i][3]=='O' && s[i][4]=='O')
        {   s[i][3]='+'; s[i][4]='+';
            flag=0;
        }
    }
    if(flag) cout<<"NO";
    else
    {   cout<<"YES"<<endl;
        for(int i=0; i<n; i++)
            cout<<s[i]<<endl;
    }
return 0;
}
