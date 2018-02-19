#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t, n, i;
    long int s[5000];
    cin>>t;
    while(t--)
    {   cin>>n;
        for(i=0; i<n; i++)
        {   cin>>s[i];
        }
        sort(s,s+n);
        int d=s[1]-s[0];
        for(i=1; i<n; i++)
        {   if(s[i]-s[i-1]<d)
            {   d=s[i]-s[i-1];
            }
        }
        cout<<d<<endl;
    }
}
