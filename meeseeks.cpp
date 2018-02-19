#include <iostream>
using namespace std;
int main()
{
    int n=60;
    long long arr[n+1]={0};
    arr[1]=12;
    for(int i=2; i<=n; i++)
    {   for(int j=1; j<i; j++)
            arr[i]+=arr[j];
        cout<<arr[i]<<endl;
    }
    return 0;
}
