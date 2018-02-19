#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int n;
    int sum=0, z=0, k=0;
    cin>>n;
    int inp[n];
    for(int i=0; i<n; i++)
        cin>>inp[i];
    sort(inp, inp+n);
    int ans[n];
    while(sum!=n && k!=n)
    {   int i;
        for(i=n-k; i>-1; i--)
        {   if(((inp[0]+sum)>n) && (sum<n))
            {     i=-1; break;
            }
            if((inp[i]+sum)<=n)
            {   sum+=inp[i];
                ans[z]=i;
                z++;
            }
            //cout<<i<<' ';
        }
        if(i<0 && sum<n)
        {   k++;
            while(z)
            {   ans[z]=-1; z--;
            }
            sum=z=0;
        }
    }
    if(sum<n)
        cout<<'0'<<endl;
    else
    {   cout<<z<<endl;
        for(int i=0; i<z && ans[i]!=-1; i++)
        {   cout<<inp[ans[i]]<<endl;
        }
    }
    return 0;
}
