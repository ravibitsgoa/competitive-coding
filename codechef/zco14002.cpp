#include <algorithm>
#include <iostream>
using namespace std;
int main()
{   int N;
    cin>>N;
    int arr[N];
    long long ans[N]={0};
    for(int i=0; i<N; i++)
    {   cin>>arr[i];
        if(i<3)
            ans[i] = arr[i];
        else
            ans[i] = arr[i] + min(ans[i-3], min(ans[i-2], ans[i-1]));
    }
    long long fin=ans[N-1];
    if(N>1)
        fin = min(ans[N-2], fin);
    if(N>2)
        fin = min(fin, ans[N-3]);
    cout<<fin;
    return 0;
}
