#include<iostream>
using namespace std;
int main()
{   int n, x, y, ans=0;
    cin>>n;
    y=0;
    while(n--)
    {   cin>>x;
        if(y!=x){ans++;}
        y=x;
    }
    cout<<ans<<endl;
return 0;
}
