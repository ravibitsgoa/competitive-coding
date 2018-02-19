#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, m, k, f[101]={0};
        cin>>n>>m>>k;
        for(int i=0; i<m; i++)
        {   int x; cin>>x;
            f[x]++;
        }
        for(int i=0; i<k; i++)
        {   int x; cin>>x;
            f[x]++;
        }
        int a1=0, a2=0;
        for(int i=1; i<n+1; i++)
        {   if(f[i]==2) a1++;
            else if(f[i]==0) a2++;
        }
        cout<<a1<<' '<<a2<<endl;
    }
    return 0;
}
