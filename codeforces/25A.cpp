#include<iostream>
using namespace std;
int main()
{   int n, num[101], i, evenn;
    cin>>n;
    for(i=0; i<n; i++)
    {   cin>>num[i];
    }
    if(num[0]%2 != num[1]%2)
    {   if(num[0]%2 != num[2]%2)
        cout<<1;
        else cout<<2;
    }
    else
    {   evenn=num[0]%2;
        for(i=1; i<n; i++)
        {   if(num[i]%2 != evenn)
            {   cout<<i+1; break;
            }
        }
    }
    return 0;
}
