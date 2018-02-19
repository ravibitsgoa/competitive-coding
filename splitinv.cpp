#include<iostream>
using namespace std;
void mergesort(int p[], int i, int l, long long int &ans)
{ if(l>1)
  { mergesort(p, i, l/2, ans);
    mergesort(p, i+(l/2), l-(l/2), ans);
    int z[l], k, a=0, b=0;
    for(k=0; k<l; k++)
    { if(p[i+a]<=p[i+(l/2)+b] && a<l/2)  {z[k]=p[i+a]; a++;}
      else if(b<l-(l/2))
      { if(p[i+(l/2)+b]<p[i+a]) {ans+=l/2 - a;}
        z[k]=p[i+(l/2)+b]; b++;
      }
      else {z[k]=p[i+a]; a++;}
    }
    for(int k=0; k<l; k++)
    { p[i+k]=z[k];//copying. the linear work.
    }
  }
  else {}//base case: already sorted.
}
int main()
{ int x[100000];
  long long int ans=0;
  for(int i=0; i<100000; i++)
    cin>>x[i];
  mergesort(x, 0, 100000, ans);
  cout<<ans<<endl;
  return 0;
}
