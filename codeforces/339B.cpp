#include<iostream>
using namespace std;
int main()
{   long long int n, m, h=1, sum=0;
    cin>>n>>m;
    while(m--)
    {   long long int x;
        cin>>x;
        if(x<h) {sum+= n+x-h;}
        else    {sum+=x-h;}
        h=x;
    }
    cout<<sum;
    return 0;
}
