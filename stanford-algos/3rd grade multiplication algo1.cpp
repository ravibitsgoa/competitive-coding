#include<iterator>
#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
int main()//coursera week 1
{   string x, y; //pro is product of x & y.
    cin>>x>>y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    //input phase is complete.
    int i, j, pro[10000]={0};
    for(j=0; j<y.length(); j++)
    {   for(i=0; i<x.length(); i++)
        {   pro[i+j]+=x[i]*y[j];
            if(pro[i+j]>9)
            {   pro[i+j+1]+=pro[i+j]/10;
                pro[i+j]%=10;
            }
            cout<<x[i]<<y[j]<<pro[i+j];
        }
    }
    reverse(pro[0], pro[0] + sizeof(pro)/4);
    cout<<endl<<pro[0];

    return 0;
}
