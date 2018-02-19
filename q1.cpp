#include<iostream>
using namespace std;
int main()
{   int t, i;
    cin>>t;
    string s[t];
    for(i=0; i<t; i++)
    {   cin>>s[i];
        if(s[i][s[i].length()-1]=='y')
        {   cout<<"Case #"<<i+1<<": "<<s[i]<<" is ruled by nobody."<<endl;
        }
        else if(s[i][s[i].length()-1]=='a' || s[i][s[i].length()-1]=='e' ||s[i][s[i].length()-1]=='i' ||s[i][s[i].length()-1]=='o' ||s[i][s[i].length()-1]=='u')
        {   cout<<"Case #"<<i+1<<": "<<s[i]<<" is ruled by a queen."<<endl;
        }
        else
        {   cout<<"Case #"<<i+1<<": "<<s[i]<<" is ruled by a king."<<endl;
        }
    }
    return 0;
}
