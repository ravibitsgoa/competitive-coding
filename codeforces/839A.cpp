#include<iostream>
using namespace std;
int main()
{   int n, k;
    cin>>n>>k;
    int sum=0, i;
    for(i=1; i<=n; i++)
    {   int x;
        cin>>x;
        sum+=x;
        int temp=min(sum, 8);
        k-=temp;
        sum-=temp;
        if(k<=0)
            break;
    }
    if(k<=0)
        cout<<i;
    else
        cout<<-1;
    return 0;
}
