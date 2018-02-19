#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c[5]={0,0,0,0,0};
        while(n--)
        {   string s;
            cin>>s;
            if(s=="cakewalk")
                c[0]++;
            else if(s=="simple")
                c[1]++;
            else if(s=="easy")
                c[2]++;
            else if(s=="medium" || s=="easy-medium")
                c[3]++;
            else if(s=="hard" || s=="medium-hard")
                c[4]++;
        }
        if(c[0]>0 && c[1]>0 && c[2]>0 && c[3]>0 && c[4]>0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
