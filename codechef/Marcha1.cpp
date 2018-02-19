#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t, n, m, Ar[20], i, sum;
    cin>>t;
    while(t--)
    {   cin>>n;
        cin>>m;
        sum=0;
        for(i=0; i<n; i++)
        {   cin>>Ar[i];
        }
        sort(Ar, Ar+n);
        for(i=n-1; i>-1; i--)
        {   if(Ar[i]<=m)
            {   break;
            }
        }
        if(i==-1){cout<<"No"<<endl;}
        for(; i>-1; i--)
        {   sum+=Ar[i];
            if(sum>m){sum-=Ar[i];}
            if(sum==m){cout<<"Yes"<<endl;break;}
        }
        if(i==-1 && sum!=m){cout<<"No"<<endl;}
    }
    return 0;
}
