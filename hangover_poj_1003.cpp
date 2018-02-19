#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   float sum, T[280];
    int n, i=2;
    T[1]=0.5;
    for(n=2; n<280; n++)
        T[n] = T[n-1] + 1.00/(n+1);
    while(cin>>sum && sum>0)
    {   for(i=1; i<n && T[i]<sum; i++)
        {}
        cout<<i<<" card(s)"<<endl;
    }
return 0;
}
