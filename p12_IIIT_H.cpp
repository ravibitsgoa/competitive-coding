#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
using namespace std;
int sumdig(long long int n)
{   int sum=0;
    while(n)
    {   sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{   int q=100;
    long long int c, i, d, x;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin>>q;
    while(q--)
    {   //cin>>c;
        c=1000000000000000000;
        for(i=1; i<100; i++)
        {   d=sqrt(i*i + 4*c);
            x=(d-i)/2;
            if(sumdig(x)==i && (int)d==d && (int)(d-i)%2==0)
            {   cout<<x<<'\n'; break;
            }
        }
        if(i>=100)
            cout<<-1<<'\n';
    }
    return 0;
}
