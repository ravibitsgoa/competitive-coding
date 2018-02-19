#include<iostream>
using namespace std;
int main()
{   int n;
    while(cin>>n && n)
    {   int rem[n+2];
        int i, j;
        for(i=0; i<n+1; i++)
        {   rem[i]=0;
            for(j=0; j<=i; j++)
            {   rem[i]=((rem[i]*10) +1)%n;
            }
            //cout<<i<<' '<<rem[i]<<endl;
            for(j=0; j<i; j++)
            {   if(rem[j]==rem[i])
                break;
            }
            if(rem[j]==rem[i] && j!=i)
            break;
        }
        //This is optimized version, for bigger n. (e.g. 10000.) For small n, optimized and non-optimized version both will run equally fast.
        for(int x=i-j; x>0; x--)
        {   cout<<'1';
        }
        j++;
        while(j)
        {   cout<<'0';
        j--;
        }
        cout<<endl;
    }
    return 0;
}
