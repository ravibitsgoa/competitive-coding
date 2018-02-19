#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        int i, a1=0, a2=0, a3=0, a4=0, a5=0, a6=0;
        for(i=0; i<n && a[i]==1; i++)   a1++;
        for(; i<n && a[i]==2; i++)      a2++;
        for(; i<n && a[i]==3; i++)      a3++;
        for(; i<n && a[i]==4; i++)      a4++;
        for(; i<n && a[i]==5; i++)      a5++;
        for(; i<n && a[i]==6; i++)      a6++;
        for(; i<n && a[i]==7; i++);
        if(a1>0 && a2>0 && a3>0 && a4>0 && a5>0 && a6>0)
        {   for(; i<n && a[i]==6; i++)      a6--;
            for(; i<n && a[i]==5; i++)      a5--;
            for(; i<n && a[i]==4; i++)      a4--;
            for(; i<n && a[i]==3; i++)      a3--;
            for(; i<n && a[i]==2; i++)      a2--;
            for(; i<n && a[i]==1; i++)      a1--;
            for(; i<n && a[i]==6; i++)      a6--;
            if(a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0 && i==n)
            {   cout<<"yes"<<'\n';
                continue;
            }
        }
        cout<<"no"<<'\n';
    }
    return 0;
}
