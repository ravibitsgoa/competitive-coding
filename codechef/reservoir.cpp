#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, m;
        cin>>n>>m;
        string res[n];
        for(int i=0; i<n; i++)
            cin>>res[i];
        int flag=0;
        for(int i=0; i<n && flag==0; i++)
        {   if(res[i][0]=='W' || res[i][m-1]=='W')
                flag=1;
            for(int j=0; j<m && flag==0; j++)
            {   if(res[i][j]=='W')
                {   if((j<m-1 && res[i][j+1]=='A')||(j>0 && res[i][j-1]=='A'))
                    {flag=1; break;}
                    if((i>0 && res[i-1][j]=='B'))
                    {flag=1; break;}
                }
                else if(res[i][j]=='A')
                {   if((i>0 && res[i-1][j]!='A'))
                    {flag=1; break;}
                }
            }
        }
        if(flag)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}
