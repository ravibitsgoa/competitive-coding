#include <vector>
//#include <map>
//#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

const int MAX = 1e6;
int freq[MAX+1]={0};
//vector<int> freq(MAX+1, 0);
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    assert(n <= 1e6);
    int arr[n], max_element=0;
    for(int i=0; i<n; i++)
    {   cin>>arr[i];
        if(max_element < arr[i])
            max_element = arr[i];
    }
    assert(max_element <= 1e6);
    //cout << max_element<<endl;

    for(int i=0; i<n; i++)
    {
        freq[arr[i]]++;
    }

    //sort(arr, arr+n);
    int ans=0;
    for(int factor=1; factor<=max_element-k; factor++)
    {
        for(int ele=factor; ele<=max_element-k; ele += factor)
        {
            if((ele+k) % factor == k)
                ans += freq[ele+k]*freq[factor];
        }
    }
    auto range_found = upper_bound(arr, arr+n, k);
            
    ans+= (arr+n-upper_bound(arr, arr+n, k))*freq[k];
    
    cout << ans;
}
