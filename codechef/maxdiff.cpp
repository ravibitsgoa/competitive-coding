#include<algorithm>
#include<iostream>
using namespace std;
int main()
{   int t, n, k;
    cin>>t;
    while(t--)
    {   cin>>n>>k;
        int ele[n], sum=0;
        for(int i=0; i<n; i++)
        {   cin>>ele[i];sum+=ele[i];
        }
        sort(ele, ele+n);
        for(int i=0; i<k; i++)
        {   sum-=2*ele[i];
        }
        if(sum<0){sum=-sum;}
        cout<<sum<<endl;
    }
return 0;
}
