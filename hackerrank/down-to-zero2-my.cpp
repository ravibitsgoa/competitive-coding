#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{   
    const int NMAX = 1e6 + 5, inf = 1e7;
    int steps[NMAX]={0};
    steps[0]=0;
    steps[1]=1;
    steps[2]=2;
    
    for(int i=3; i<NMAX; i++)
    {
        steps[i] = inf;
    }
    
    for(int i=2; i<NMAX-1; i++)
    {
        steps[i+1] = min(steps[i+1], steps[i]+1);
        for(int j=2*i; j<NMAX; j+=i)
        {
            steps[j]= min(steps[j], steps[max(i, j/i)] + 1);
        }
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout << steps[x]<<'\n';
    }
}
