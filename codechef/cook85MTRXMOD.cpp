#include<iostream>
using namespace std;
int main()
{   int n, q;
    cin>>n>>q;
    int b[n+1][n+1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>b[i][j];
    int a[n+1];
    a[1]= 0;
    int i;
    for(i=2; i<=n; i++)
    {   if(b[1][i] == 0)
            a[i]= 0;
        else
            break;
    }
    a[i]= -b[1][i];
    for(int j=i+1; j<=n; j++)
    {   a[j]=b[1][j];
        if(b[j][i] != b[1][j]+ b[1][i])
            a[j]*=-1;
    }
    for(int j=1; j<=n; j++)
        cout<<a[j]<<' ';
    cout<<'\n';
    while(q--)
    {   int p;
        cin>>p;
        for(int i=1; i<=n; i++)
        {   cin>>b[i][p];
            b[p][i]=b[i][p];
        }
        a[1]= 0;
        int i;
        for(i=2; i<=n; i++)
        {   if(b[1][i] == 0)
                a[i]= 0;
            else
                break;
        }
        a[i]= -b[1][i];
        for(int j=i+1; j<=n; j++)
        {   a[j]=b[1][j];
            if(b[j][i] != b[1][j]+ b[1][i])
                a[j]*=-1;
        }
        for(int j=1; j<=n; j++)
            cout<<a[j]<<' ';
        cout<<'\n';
    }
    return 0;
}
