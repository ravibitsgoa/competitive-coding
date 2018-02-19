#include <iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   long long n;
        cin>>n;
        n/=10;
        int ans=0;
        while(n)
        {   ans+= (n%10);  
            n/=100;
        }
        cout << ans << '\n';
    }
}
