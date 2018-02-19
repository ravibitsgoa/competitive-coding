#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    int hor[n]={0},ver[n]={0};
    for(int i=0; i<(n*n); i++)
    {   int x,y;
        cin>>x>>y; x--; y--;
        if(hor[x]==0 && ver[y]==0)
        {   hor[x]=1; ver[y]=1;
            cout<<i+1<<' ';
        }
    }
    return 0;
}
