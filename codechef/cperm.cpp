#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        //long long int ans=1;
        /*for(int i=1; i<n; i++)
        {   ans*=2;
            ans%=(1000000007);
        }*/
        cout<<(1<<(n-1))-2<<endl;
    }
    return 0;
}
