#include <iostream>
using namespace std;
int main()
{   
    long long n=1e17;
    cout << n<<endl;
    long long mod = 1e9+7;
    long long s = (n/8)%mod;
    s= (s*(((n-1)/3) %mod)) % mod;
    s%= mod;
    s= (s*((n-2) %mod)) % mod;
    s= (s*((n+1) %mod)) % mod;
    cout << s;
}
