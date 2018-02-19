#include<iostream>
using namespace std;
int main()
{   long long int a, n, k, i;
    cin>>a; cin>>n; cin>>k;
    n++;
    /*cout<<(a%n)<<' ';
    k--;
    for(i=n; k>0; i*=n)
    {   cout<<a/i<<' ';
        k--;
    }*/
    for(i=0; i<k; i++)
    {   cout<<a%n<<' ';
        a/=n;
    }
    return 0;
}
