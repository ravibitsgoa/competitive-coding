#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        a[i]=i+1;
        //cin>>a[i];
    int c[n], j=0, i=0, l=pow(3,n);
    int *sum;
    sum=(int *)malloc(sizeof(int)*(l+1));
    *(sum+j)=0;
    for(i=0; i<n; i++)
    {   c[i]=-1;
        *(sum+j)-=a[i];
        //cout<<*(sum+j);
    }
    //cout<<*(sum+j);
    int z=l;
    while(c[n-1]<=1)
    {   i=0;
        while(c[i]<1)
        {   *(sum+j)=a[i]+*(sum+j-1);
            c[i]++; j++;
            //cout<<c[2]<<' '<<c[1]<<' '<<c[0]<<endl;
            cout<<*(sum+j)<<endl;
        }
        while(c[i]>=1)
        {   if(i==n-1 && c[i]==1)
            {   c[i]++;
                break;
            }
            c[i]=-1;
            if(!(*(sum+j)))
                *(sum+j)=*(sum+j-1)-2*a[i];
            else
                *(sum+j)-=2*a[i];
            i++;
        }
        //cout<<i;
        c[i]++;
        if(!*(sum+j))
            *(sum+j)=*(sum+j-1)+a[i];
        else
            *(sum+j)+=a[i];
    }
    int q;
    /*cin>>q;
    while(q--)
    {   int k;
        cin>>k;
        if(find(sum, sum+z, k)==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }*/
    for(i=0; i<z; i++)
        cout<<*(sum+i)<<endl;
    return 0;
}
