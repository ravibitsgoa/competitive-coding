//Arrival of the general
#include<iostream>
using namespace std;
int main()
{   int n, A[101], H, s;
    cin>>n;
    for(int i=1; i<=n; i++)
    {   cin>> A[i];
    }
    H=1; s=1;
    for(int i=1; i<=n; i++)
    {   if(A[i]<=A[s]){s=i;}
        else if(A[i]>A[H]){H=i;}
    }
    if(s>H)
    {   cout<<(n-s +H -1);
    }
    else
    {   cout<<(n-s + H -2);

    }
    return 0;
}
