#include<iostream>
using namespace std;
int main()
{   int n, k;
    cin>>n>>k;
    string x;
    cin>>x;
    int open[26]={0}, start[26], end[26];
    for(int i=0; i<n; i++)
    {   if(open[x[i]-'A']==0)
        {   open[x[i]-'A']=1;
            start[x[i]-'A']=i;
        }
        end[x[i]-'A']=i;
    }
    int count=0, mx=0;
    for(int i=0; i<n; i++)
    {   if(start[x[i]-'A']==i)
        {   count++;
            mx=max(mx, count);
        }
        if(end[x[i]-'A']==i)
        {   count--;
        }
    }
    if(mx<=k)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
