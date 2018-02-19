#include<bits/stdc++.h>
using namespace std;
int ciel(float a)
{ if(a==(int)a)
    return (int)a;
  else
    return 1+(int)a;
}
int main()
{ int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--)
  { int n, x, ones=0;
    cin>>n;
    for(int i=0; i<n*n; i++)
    { cin>>x;
      ones+=x;
    }
    //cout<<ones;
    /*if(ones<=n)
      cout<<0<<'\n';
    else
    { cout<<'a';
      int k=(2*n -1);
      float a=(2*n -1)*(2*n -1) - 4*(ones-n);
      k-= ciel(sqrt(a));
      cout<<k;
      if(k%2)
        k++;
      k/=2;
      cout<<a<<k<<'\n';
    }*/
    int sum=n, i=1;
    while(sum<ones)
    { sum+=2*(n-i);
      i++;
    }
    i--;
    cout<<i<<'\n';
  }
  return 0;
}
