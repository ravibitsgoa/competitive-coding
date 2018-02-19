//CS Academy
#include <iostream>

using namespace std;

int main() {
    int n, start=0, end=0;
    cin>>n;
    int arr[n], ans=0;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    while(1)
    {   //cout<<start;
		while(arr[start]==0 && start<n)
            start++;
        if(start>=n)
            break;
        int mn= arr[start], i;
        for(i=start+1; i<n; i++)
        {   if(arr[i]==0)
                break;
            else
                mn= min(mn, arr[i]);
        }
        ans++;
		//cout<<mn;
        for(int j=start; j<i && j<n; j++)
            arr[j]-=mn;
    }
    cout<<ans;
    return 0;
}