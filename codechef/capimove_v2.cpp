#include<vector>
#include<map>
#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        map<int, int> pl;
        int x;
        for(int i=1; i<=n; i++)
        {   cin>>x;
            pl[x]=i;
        }
        int y;
        map<int, vector<int> > adj;
        for(int i=1; i<n; i++)
        {   cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1; i<=n; i++)
        {   int f[n+1]={0}, l=adj[i].size();
            for(int k=0; k<l; k++)
                f[adj[i][k]]=1;
            f[i]=1;
            for(map<int, int>::reverse_iterator j=pl.rbegin(); j!=pl.rend(); j++)
            {   if(f[j->second]==0)
                {   cout<<(j->second)<<' ';
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
