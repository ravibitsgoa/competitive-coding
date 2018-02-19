#include<iostream>
using namespace std;
int main()
{   int x, flag=0;
    while(cin>>x)
    {   if(x==42){flag=1;}
        if(flag==0) {cout<<x<<endl;}
    }
    return 0;
}
