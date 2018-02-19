#include<cmath>
#include<iostream>
using namespace std;
int main()
{   int n, i;
    string a[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cin>>n;
    if(n<=5)
    {   cout<<a[n-1];
        return 0;
    }
    for(i=0; ; i++)
    {   if(n>5*(1<<i))
            n-=5*(1<<i);
        else
            break;
    }
    n=n/(1<<i);
    cout<<a[n];
    return 0;
}
