#include<iostream>
using namespace std;
int mx(int a, int b)
{ if(a>=b) return a;
  return b;
}
int mn(int a, int b)
{ if(a>=b) return b;
  return a;
}

int main()
{ long long int n, m, x, y;
  long long int k;
  cin>>n>>m>>k>>x>>y;
  long long int max=k/(n*m), min=max>>1, s=min;
  //k%=(2*n*m);
  if(k%(2*n*m)>n*m)
  {  min++; max++;
  }
  if(k% (n*m)!=0)
    max++;
  if(k>n*m)
  { k%=(n*m*2);
    if(k<=x*y)
      s++;
    k-=n*m;
    if(k<=(n-x)*(m-y))
      s++;
  }
  //long long int f[n][m]={0}; long long int al=k;
  /*for(int i=0; i<n; i++)
  { for(int j=0; j<m; j++, k--)
    { f[i][j]=max+(k>0);
    }
  }
  for(int i=n-1; i>=0 && k!=0; i--)
  { for(int j=0; j<m && k!=0; j++, k--)
      f[i][j]++;
  }*/
  //min=max=f[0][0];
  //if(nm)
    //nm=f[0][0];
  /*for(int i=0; i<n; i++)
  { for(int j=0; j<m && al; j++, al--)
    { max=mx(max, f[i][j]);
      min=mn(min, f[i][j]);
    }
  }*/

  //s=f[x-1][y-1];
  //cout<<mm<<' '<<nm<<endl;
  //max=mm; min=nm;
  cout<<max<<' '<<min<<' '<<s;
  return 0;
}
