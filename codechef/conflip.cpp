#include<iostream>
using namespace std;
int main()
{   int t, g, i, n, q, ans;
    cin>>t;
    while(t--)
    {   cin>>g;
        while(g--)
        {   cin>>i; cin>>n; cin>>q;
            ans=(int)(n/2);
            ans+=(n%2!=0)&&(i!=q);
            /*if(n%2 ==0)
            {   ans=n/2;
            }
            else
            {   if(i==q)
                {
                }
                else
                {   ans=1+(int)(n/2);
                }
            }*/
            cout<<ans<<endl;
        }
    }
return 0;
}
