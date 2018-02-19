#include<iostream>
using namespace std;
const int MOD = 20011;
int main()
{   int r, c, d;
    cin>>r>>c>>d;
    int open[r][c];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>open[i][j];
    long long hori[r][c]={0}, ver[r][c]={0};
    hori[0][0]=ver[0][0]=1;
    d++;
    for(int i=1; i<r; i++)
    {   hori[i][0] = 0;
        if(open[i][0]==0)
        {   ver[i][0]=0;
            continue;
        }
        ver[i][0] = ver[i-1][0];
        if (i>=d)
            ver[i][0]-= ver[i-d][0];
        ver[i][0] = max(0ll, ver[i][0]);
        ver[i][0]%=MOD;
    }
    for(int j=1; j<c; j++)
    {   ver[0][j] = 0;
        if(open[0][j]==0)
        {   hori[0][j]=0;
            continue;
        }
        hori[0][j] = hori[0][j-1];
        if (j>=d)
            hori[0][j]-= hori[0][j-d];
        hori[0][j] = max(0ll, hori[0][j]);
        hori[0][j]%=MOD;
    }
    for(int i=1; i<r; i++)
    {   for(int j=1; j<c; j++)
        {   hori[i][j]  = hori[i][j-1] + ver[i][j-1];
            if(j>=d)
                hori[i][j]-= hori[i][j-d];

            ver[i][j]   = hori[i-1][j] + ver[i-1][j];
            if(i>=d)
                ver[i][j]-= ver[i-d][j];

            hori[i][j]  = max(hori[i][j], 0ll);
            ver[i][j]   = max(ver[i][j], 0ll);
            if(open[i][j]== 0)
                hori[i][j]= ver[i][j] = 0;
            hori[i][j]%=MOD;
            ver[i][j]%=MOD;
        }
    }
    /*for(int i=0; i<r; i++)
    {   for(int j=0; j<c; j++)
            cout<<hori[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<r; i++)
    {   for(int j=0; j<c; j++)
            cout<<ver[i][j]<<' ';
        cout<<endl;
    }*/

    cout<<(hori[r-1][c-1] + ver[r-1][c-1])%MOD;
    return 0;
}
