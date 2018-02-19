#include<iostream>
using namespace std;
int main()
{   int n, i, in=1, c=0;
    cin>>n;
    int per[n+2], val[n+2]={0};
    for(i=1; i<=n; i++)
    {   cin>>per[i];
    }
    do{   i=in;
        do
        {   val[i]=1;
            i=per[i];//cout<<i;
        }while(i!=in);
        c++;
        for(int j=1; j<=n+1; j++)
        {   if(val[j]==0){in=j;break;}
        }
    }while(in<=n);
    cout<<c<<endl;
    in=1;
    for(i=1; i<=n; i++)
    {val[i]=0;}
    while(c--)
    {   i=in;
        do
        {   val[i]=1;
            cout<<i<<' ';
            i=per[i];
        } while(i!=in);
        cout<<i<<endl;
        for(int j=1; j<=n; j++)
        {   if(val[j]==0){in=j; break;}
        }
    }
return 0;
}
