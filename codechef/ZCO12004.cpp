#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++)
        cin>>arr[i];

    long long sum[N]={0};
    sum[0]= arr[0];
    sum[1]= arr[1];
    for(int i=2; i<N; i++)
    {   sum[i] = arr[i];
        if(sum[i-2]< sum[i-1])
            sum[i]+= sum[i-2];
        else
            sum[i]+= sum[i-1];
    }

    long long ans1= sum[N-1], ans2;
    sum[N-1]= arr[N-1];
    sum[N-2]= arr[N-2];
    for(int i=N-3; i>-1; i--)
    {   sum[i] = arr[i];
        if(sum[i+2]< sum[i+1])
            sum[i]+= sum[i+2];
        else
            sum[i]+= sum[i+1];
    }
    ans2=sum[0];
    cout<<min(ans1, ans2);
    return 0;
}
