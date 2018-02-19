#include<algorithm>
#include<iostream>
using namespace std;
int main()
{   int n, a, b;
    cin>>n>>a;
    int x[a], z[n];
    for(int i=0; i<a; i++)
    {   cin>>x[i];
    }
    cin>>b;
    int y[b];
    for(int i=0; i<b; i++)
    {   cin>>y[i];
    }
    sort(x, x+a);
    sort(y, y+b);
    for(int i=0, j=0, k=0; i<a || j<b; )
    {   if(x[i]<=y[j])
        {   if(z[k-1]!=x[i]) {z[k]=x[i]; k++;}
            i++;

        }
        else if(y[j]<x[i])
        {   if(z[k-1]!=y[j]) {z[k]=y[j]; k++;}
            j++;
        }
    }
    int i;
    for(i=1; i<n; i++)
    {   if(z[i]-z[i-1] >1)
        {   cout<<"Oh, my keyboard!";
            break;
        }
    }
    if(i==n && z[n-1]==n) cout<<"I become the guy.";
    return 0;
}
