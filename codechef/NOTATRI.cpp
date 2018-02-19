#include <iostream>
#include <algorithm>
using namespace std;
int main()
{   int n;
    cin>>n;
    while(n)
    {
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        int ans=0;
        for(int i=0; i<n; i++)
        {   for(int j=i+1; j<n; j++)
            {   auto iter = upper_bound(arr, arr+n, arr[i]+arr[j]);
                ans+= arr+n-iter;
            }
        }
        cout << ans<<'\n';
        cin>>n;
    }
}
