#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    int len=0, x, lenmax=0;
    while(n--)
    {   cin>>x;
        if(x) len++;
        else
        {   if(len>lenmax) lenmax=len;
            len=0;
        }
    }
    if(len>lenmax) lenmax=len;
    cout<<lenmax;
    return 0;
}
