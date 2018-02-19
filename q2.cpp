#include<iostream>
using namespace std;
int main()
{   int t, n;
    cin >>t;
    while(t--)
    {   cin>>n;
        int t[n][3], i, a=0, b=0, c=0;
        for(i=0; i<n; i++)
        {   cin>>t[i][0]>>t[i][1]>>t[i][2];
            if(t[i][0]>a){a=i;}
            if(t[i][1]>b){b=i;}
            if(t[i][2]>c){c=i;}
        }
        if(t[a][0]+t[b][1]+t[c][2]<=10000){cout<<n;}
        else if(t[a][0]+t[b][1]<=10000 || t[a][0]+t[c][2]<=10000 ||t[a][0]+t[b][1]<=10000){cout<<;}
    }
}
