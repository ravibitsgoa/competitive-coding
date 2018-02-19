#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int T=1; T<=t; T++)
    {
        int E, n, h=0;
        cin>>E>>n;
        int arr[n], j=n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        //cout<<E<<endl;
        for(int i=0; i<j && i<n; i++)
        {   //cout<<i<<' ';
            if(E > arr[i])
            {   //cout<<arr[i]<<endl;
                E-=arr[i];
                h++;
            }
            else if(h>0 && i<(j-1))
            {   //cout<<j<<endl;
                E+= arr[j-1];
                j--;
                E-= arr[i];
            }
            else
            {
                break;
            }
        }
        cout<<"Case #"<<T<<": "<<h<<'\n';
    }
    return 0;
}
