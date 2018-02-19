#include<iostream>
using namespace std;
int main()
{   int n, p, q, a[100], b[100], c[200], i, j, k;
    cin>>n;
    cin>>p;
    for(i=0; i<p; i++)
    {   cin>>a[i];
    }
    cin>>q;
    for(i=0; i<q; i++)
    {   cin>>b[i];
    }
    j=0; k=0;
    //merge sorting below:
    for(i=0; i<p || j<q; )
    {   if(a[i]<=b[j]){c[k]=a[i]; i++;}
        else{c[k]=b[j]; j++;}
        k++;
    }
    if(c[k-1]!=n)
    {   cout<<"Oh, my keyboard! a"; return 0;}
    for(i=1; i<k; i++)
    {   if(c[i]-c[i-1]>1){cout<<"Oh, my keyboard! b"; break;}
    }
    if(i==k){cout<< "I become the guy.";}
    return 0;
}
