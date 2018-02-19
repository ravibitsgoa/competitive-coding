#include<iostream>
using namespace std;
int main()
{ int T;
  cin>>T;
  while(T--)
  { int N, M;
    cin>>N>>M;
    char x[N][M];
    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        cin>>x[i][j];
    for(int i=0; i<N; i++)
    { for(int j=0; j<M; j++)
      { if(x[i][j]=='L')
        { for(int k=0; k<M; k++)
          { if(x[i][k]=='E')
              x[i][k]='.';
          }
          for(int k=0; k<i; k++)
          { if(x[k][j]=='E')
              x[k][j]='.';
          }
        }
      }
    }
    int gaya=1;
    for(int i=0; i<N; i++)
    { for(int j=0; j<M; j++)
      { if(x[i][j]=='E')
          gaya=0;
      }
    }
    if(gaya)
      cout<<"Possible\n";
    else
      cout<<"Impossible\n";
  }
return 0;
}
