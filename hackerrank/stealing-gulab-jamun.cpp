#include <iostream>
typedef long long ull;
using namespace std;
ull f(ull n)
{ ull r, m=0;
  for(r=2; r*r*r <= n; r++)
  { m += n/(r*r*r);
  }
  return m;
}
ull binary(ull ini, ull fin, ull m)
{   ull i;
    //cout<<ini<<' '<<fin<<' ';
    i=(ini+fin)/2;
    ull fi=f(i);
    if(fin==ini+1)
    { if(f(fin)==m && f(ini)!=m)  return fin;
      else if(f(ini)==m)          return ini;
      else                        return -1;
    }
    if(fi==m && f(i-1)<m)       return i;
    else if(fi<m && f(i+1)>m)   return -1;
    else if(fi>m && f(i-1)<m)   return -1;
    else if(fi>=m)              return binary(ini, i, m);
    else                        return binary(i, fin, m);
}

int main()
{
  ull arr[100]={0, 1}, sum[100]={0};
  for(int i=2; i<100; i++)
  { arr[i]=i;
    sum[i]=f(arr[i]);
  }
  //int t=15;
  //cin>>t;
  for(ull m=1; m<=15; m++)
  {
    //ull m=t;
    //cin>>m;
    /*int i;
    for(i=0; i<17; i++)
    { if(m<=sum[i])
        break;
    }*/
    //if(i>1)
      //cout<<binary(arr[i-2], arr[i], m)<<'\n';
    //else
    ull ans= binary(1, 100, m);
    for(int i=1; i<100; i++)
      if(sum[i]==m)
      { cout<<i;
        break;
      }
    cout<<' '<<ans<<' '<<m<<'\n';
  }
return 0;
}
