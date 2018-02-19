#include<iostream>
#define MOD 1000000007
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int p, q, r;
    long long sum=0;
    cin>>p>>q>>r;
    int A[p], B[q], C[r], sy2[q]={0}, sy[q]={0}; //sy[i]= sigma y[j>=i], sy[i]= sigma y^2 [j>=i]
    for(int i=0; i<p; i++)
      cin>>A[i];
    for(int i=0; i<q; i++)
      cin>>B[i];
    for(int i=0; i<r; i++)
      cin>>C[i];
    sy[q-1]  = B[q-1];
    sy2[q-1] = B[q-1] * B[q-1];
    for(int i=q-2;; i>=0; i--)
    { sy[i] += sy[i+1]  + B[i];
      sy2[i]+= sy2[i+1] + B[i]*B[i];
    }
    int xiterator=0, ziterator=0, yiterator=0;
    for(; xiterator<p && ziterator<r; )
    { sum+=A[xiterator]*C[ziterator]*;
      while( B[yiterator] < max(A[xiterator], C[ziterator]) )
        yiterator++;
      sum+=sy2[yiterator]*min(r+1-ziterator, p+1-xiterator);
      sum+=(A[xiterator]+C[ziterator])*sy[yiterator];
      if(A[xiterator]<=C[ziterator])
        xiterator++;
      else
        ziterator++;
    }

  }
return 0;
}
