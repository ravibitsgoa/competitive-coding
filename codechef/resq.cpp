#include<cmath>
#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        for(int i=sqrt(n); i>0; i--)
        {   if(n%i==0) {cout<<(n/i)-i<<endl; break;}
        }
    }
    return 0;
}
