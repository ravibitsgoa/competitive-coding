#include<iostream>
using namespace std;

long long sqroot(long long start, long long end, long long n)
{   long long mid;
    mid=(start+end)/2;
    if(mid*mid<=n && (mid+1)*(mid+1)>n) return mid;
    else if(mid*mid>n)                  return sqroot(start, mid, n);
    else                                return sqroot(mid, end, n);
}

int main()
{   int t;//no of test cases
    cin>>t;
    while(t--)
    {   long long n;
        cin>>n;
        cout<<sqroot(1,n,n)<<endl;
    }
    return 0;
}
