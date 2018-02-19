#include<iostream>
using namespace std;
int main()//prime test
{   int arr[100005]={0};
    for(int i=1; i<100005; i++)
    {   arr[i]=i;
    }
    for(int i=2; i<100005; i++)
    {   if(arr[i]!=-1)
        {   for(int j=2; j*i<100005; j++)
            {   arr[i*j]=-1;
                //cout<<i*j<<' ';
            }
        }
    }
    //sieve algorithm.
    int t, n;
    cin>>t;
    while(t--)
    {   cin>>n;
        if(arr[n]!=n){cout<<"no"<<endl;}
        else{cout<<"yes"<<endl;}
        //cout<<arr[n];
    }
    return 0;
}
