#include<iostream>
using namespace std;
int main()
{   long long int n, k;
    cin >> n ; cin>>k;
    if(n%2==0)
    {   if(k<=n/2)  {cout<<(2*k - 1);}
        else        {cout<<(2*k - n);}
    }
    else
    {   if(k<=(long long int)(n/2)) {cout<<(long long int)(2*k - 1);cout<<'b';}
        else                        {cout<<(2*k -n -1);cout<<'a';}
    }
    return 0;
}
