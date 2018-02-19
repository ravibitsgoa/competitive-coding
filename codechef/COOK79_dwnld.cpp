#include<iostream>
using namespace std;
int main()
{   int tc;
    cin>>tc;
    while(tc--)
    {   int n, k;
        cin>>n>>k;
        int t[n], d[n], sum=0, flag=0;
        for(int i=0; i<n; i++)
        {   cin>>t[i]>>d[i];
        }
        for(int i=0; i<n; i++)
        {   k-=t[i];
            if(k<=0 && k>=-t[i] && flag==0)    {sum-=k*d[i]; flag=1;}
            else if(k<0) sum+=t[i]*d[i];
        }
        cout<<sum<<endl;
    }
return 0;
}
