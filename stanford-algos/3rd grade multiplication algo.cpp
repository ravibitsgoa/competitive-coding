#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()//coursera week 1
{   string x, y; //pro is product of x & y.
    cin>>x>>y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    //input phase is complete.
    int i, j, pro[2*x.length()+2]={0}, ma=0;
    for(j=0; j<y.length(); j++)
    {   for(i=0; i<x.length(); i++)
        {   pro[i+j]+=(x[i]-'0')*(y[j]-'0');    //because input is in character form. To convert it into integers, we need to -'0'
            if(pro[i+j]>9)//If there is any carry over.
            {   pro[i+j+1]+=pro[i+j]/10;
                if(ma<i+j+1) ma=i+j+1;
                pro[i+j]%=10;
            }
            if(ma<i+j){ma=i+j;}
        }
    }
    FILE *P=fopen("output of multiplication.txt","w");
    for(i=ma; i>-1; i--)
    {   cout<<pro[i];
        putc(pro[i]+'0',P);
    }
    return 0;
}
