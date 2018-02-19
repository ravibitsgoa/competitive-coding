#include<cmath>
#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    while(n--)
    {   int t;
        cin>>t;
        float a=360.0/(180.0-t);
        if(a==floor(a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
