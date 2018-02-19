#include<iostream>
using namespace std;
int main()
{   int n, k;
    cin>>n>>k;
    int x, E=100;
    for(int i=0; i<n; i++)
    {   cin>>x;
        if(x==1 && (i%k==0)) {E-=3;}
        else if((x==0) && (i%k==0)){E-=1;}
        //cout<<E<<endl;
    }
    cout<<E;
    return 0;
}
