#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int L, N;
    cin>>L>>N;
    string moves;
    cin>>moves;
    //cout<<N;
    string inp[N];
    for(int i=0; i<N; i++)
    { cin>>inp[i];
    }
    int finalans=0;
    for(int i=0; i<N; i++)
    { for(int j=0; j<N; j++)
      { //int fromhere=0;
        if(inp[i][j]=='#')
          continue;
        int i0=i, j0=j, k;
        for(k=0; k<L; k++)
        { if(moves[k]=='R') j0++;
          if(moves[k]=='L') j0--;
          if(moves[k]=='U') i0--;
          if(moves[k]=='D') i0++;
          if(i0>=N || i0<0 || j0>=N || j0<0 || inp[i0][j0]=='#')
              break;
        }
        //cout<<k<<' ';
        finalans^=k;
      }
      //cout<<endl;
    }
    cout<<finalans<<'\n';
  }
  return 0;
}
