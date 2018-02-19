#include <iostream>
#include <vector>
using namespace std;

long long ans(vector<int> &arr, int size, vector<int> &moves)
{  int m=arr[0]; 
    for(int i: arr)
        m = min(m, i);
    //cout<<m<<endl;
    long long ans=0, temp=0;
    for(int i=0; i<size; i++)
        temp+=moves[arr[i]];
 
    for(int i=0; i<size; i++)
    {   arr[i] -= m;
        ans += moves[arr[i]];
    }
    return min(ans, temp);
}

int main() {
    vector<int> moves(1000);
    moves[0]=0;
    moves[1] = moves[2] = moves[5] = 1;
    moves[3] = moves[4] = 2;
    for(int i=6; i<1000; i++)
    {   moves[i]= 1+ min(min(moves[i-1], moves[i-2]), moves[i-5]);
    }
    int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<ans(arr, n, moves)<<endl;
    }
    return 0;
}

