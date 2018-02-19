#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{   string x;
    cin>>x;
    int l=x.length(),up=0;
    for(int i=0; i<l; i++)
    {   if(x[i]<'a')
            up++;
    }
    if(2*up>l)
    {   for(int i=0; i<l; i++)
            cout<<(char)toupper(x[i]);
    }
    else
    {   for(int i=0; i<l; i++)
            cout<<(char)tolower(x[i]);
    }
    return 0;
}
