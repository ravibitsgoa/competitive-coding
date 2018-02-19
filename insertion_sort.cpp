#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main()
{   int  n=100000000;//just see the run-time.
    int *a;
    a=(int*)malloc(sizeof(int)*n);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<n; i++)
        a[i]=n-i;
    /*int i, j, key;
    for(j=0; j<n; j++)
    {   key=a[j];
        for(i=j-1; i>-1 && a[i]>key; i--)
            a[i+1]=a[i];
        a[i+1]=key;
    }*/
    sort(a, a+n);
    //for(int j=0; j<n; j++)
        //cout<<a[j]<<' ';
return 0;
}
