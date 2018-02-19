#include <iostream>
using namespace std;

vector<int> tree[n+1];
int parent[n+1]={0};
long long total=0;
long long DFS(int node)
{
    long long ans=1;
    for(int i: tree[node])
        ans*= DFS(i)+1;
    total+= ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin>>n>>k;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        tree[a].push_back(b);
        parent[b]=a;
    }
    int root = 0;
    for(int i=1; i<=n; i++)
    {
        if(parent[i] ==0)
            root = i;
    }
    assert(root != 0);
    cout << DFS(root)+1;
}
