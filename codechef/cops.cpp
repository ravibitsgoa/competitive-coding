#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int m, x, y, ans=0;
        cin>>m>>x>>y;
        int p[m];
        for(int i=0; i<m; i++) cin>>p[i];
        sort(p, p+m);
        ans=(p[0]-x*y-1)*(p[0]>x*y +1); //cout<<ans<<endl;
        ans+=(100-p[m-1]-x*y)*(100>p[m-1] + x*y); //cout<<ans<<endl;
        for(int i=1; i<m; i++)
        {   ans+=(p[i]-p[i-1]-(2*x*y) - 1)*(p[i]-p[i-1]>(2*x*y + 1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
