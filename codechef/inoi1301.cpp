#include <iostream>
#include <algorithm>
using namespace std;

//const long long INF = 1e9;

int main()
{
    long long n;
    int k;
    cin>>n>>k;
    long long arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    k--;
    long long forward[n]={0}, backward[n]={0};
    forward[k]= 0;
    for(int i=k+1; i<n; i++)
    {   forward[i]= arr[i];
        if(i>1)
            forward[i]+= max(forward[i-1], forward[i-2]);
        else
            forward[i]+= forward[i-1];
    }
    backward[0]= arr[0];
    backward[1]= arr[0]+ arr[1];
    for(int i=2; i<n; i++)
    {   backward[i]= arr[i];
        backward[i]+= max(backward[i-1], backward[i-2]);
    }
    long long ans=arr[0];
    for(int i=k; i<n; i++)
    {   ans=max(ans, forward[i] + backward[i] - arr[i]);
        cout<<ans<<'\n';
    }
    cout<<ans;
    //cout<< max(f(k), 0ll) + max( max(g(k-1), g(k-2)), 0ll);
    return 0;
}
