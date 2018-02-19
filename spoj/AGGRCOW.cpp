//http://www.spoj.com/problems/AGGRCOW/
//Aggrasive cows. binary search.
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
bool isValid(int* begin, int* end, int dMin, int cows)
{   int count=1, last=0;    //*begin is by default selected.
    for(int i=1; i<end-begin; i++)
    {   if(begin[i]-begin[last] >= dMin)
        {   last=i;
            count++;
        }
    }
    return (count>=cows);
}

int binarySearch(int* begin, int* end, int low, int high, int cows)
{   if(low==high)   return low;
    if(low>high)    assert(0);
    if(low==high-1 && isValid(begin, end, low, cows) && !isValid(begin, end, high, cows))
        return low;
    int mid=(low+high)/2;
    if(isValid(begin, end, mid, cows))
        return binarySearch(begin, end, mid, high, cows);
    return binarySearch(begin, end, low, mid, cows);
}

int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, c;
        cin>>n>>c;
        int barn[n], mx=0;
        for(int i=0; i<n; i++)
        {   cin>>barn[i];
            mx=max(mx, barn[i]);
        }
        sort(barn, barn+n);
        int ans=binarySearch(barn, barn+n, 0, mx, c);
        cout<<ans<<'\n';
    }
    return 0;
}
