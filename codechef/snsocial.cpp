#include<iostream>
#define INF 1<<30
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int m, n;
    cin>>n>>m;
    int a[n][m];
    int dist[n][m];
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        dist[i][j]=+INF;
    int mx=0;
    for(int i=0; i<n; i++)
    { for(int j=0; j<m; j++)
      { cin>>a[i][j];
        mx=max(mx, a[i][j]);
      }
    }
    int ans=0;
    //bool end=0;
    //bool changed[n][m]={0};
    for(int i=0; i<n; i++)
    { for(int j=0; j<m; j++)
      { if(a[i][j]==mx)
        { dist[i][j]=0;
        }
        else if(i>0)
        { dist[i][j]=min(dist[i-1][j]+1, dist[i][j]);
          if(j>0)
          { dist[i][j]=min(dist[i][j], dist[i-1][j-1]+1);
          }
          if(j<m-1)
          { dist[i][j]=min(dist[i-1][j+1]+1, dist[i][j]);
          }
        }
        else if(i<n-1)
        { dist[i][j]=min(dist[i][j], 1+ dist[i+1][j]);
          if(j>0)
          { dist[i][j]=min(dist[i][j], 1+ dist[i+1][j-1]);
          }
          if(j<m-1)
          { dist[i][j]=min(dist[i][j], dist[i+1][j+1]+1);
          }
        }
        else if(j>0)
        { dist[i][j]=min(dist[i][j], dist[i][j-1]+1);
        }
        else if(j<m-1)
        { dist[i][j]=min(dist[i][j], 1+dist[i][j+1]);
        }
        ans=max(ans, dist[i][j]);
      }
    }
    cout<<ans<<'\n';
  }

return 0;
}
