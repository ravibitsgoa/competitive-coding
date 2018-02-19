#include<iostream>
using namespace std;
int main()
{   int s, n, i;
    cin>>s>>n;
    int x[n], y[n];
    for(i=0; i<n; i++)
    cin>>x[i];
    for(i=0; i<n; i++)
    cin>>y[i];
    for(i=0; i<n; i++)
    {   if(x[i]<s) s+=y[i];
        else {cout<<"NO"; break;}
    }
    if(i==n) cout<<"YES";
    return 0;
}
