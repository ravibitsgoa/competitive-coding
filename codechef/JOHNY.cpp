#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int t, n, i, k, L[100];
    cin>>t;
    while(t--)
    {   cin>>n;
        for(i=0; i<n; i++)
        {   cin>>L[i];
        }
        cin>>k; k--;k=L[k];
        sort(L, L+n);
        for(i=0; i<n; i++)
        {   if(L[i]==k)
            {   cout<<i+1<<endl;
                break;
            }
        }
    }
return 0;
}
