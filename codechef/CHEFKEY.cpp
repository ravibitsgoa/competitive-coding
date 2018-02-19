#include<iostream>
using namespace std;
int main()
{   int t, n, m, c, x, y, sum;
    cin>>t;
    while(t--)
    {   cin>>n; cin>>m; cin>>c; sum=0;
        if((n*m)%c==0 && n*m >=c)
        {   for(x=1; x<=n; x++)
            {   y=c/x;
                if(c%x==0 && y<=m)
                {   sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
