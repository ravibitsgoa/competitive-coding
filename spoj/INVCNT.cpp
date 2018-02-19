//http://spoj.com/problems/INVCNT
#include<iostream>
using namespace std;
//This mergesort function takes as an argument, the starting iterator and the end iterator.
//time-complexity: O(NlogN)
long long inversions=0;
void mergesort(int *pstart, int *pend)
{ int l=pend-pstart;
  if(l>1)
  { int* mid = pstart + l/2;
    mergesort(pstart, mid);
    mergesort(mid, pend);
    int z[l];
    int k, a=0, b=0;  //a and b are the indices of the first and second halves resp, k is overall index.
    for(k=0; k<l; k++)
    { if(*(pstart+a)< *(pstart+ ((l/2)+b)) && a<l/2)
      { z[k]=*(pstart + a); a++;
      }
      else if(b<l-(l/2))
      { z[k]=*(pstart + (l/2 + b)); b++;
        if(a<l/2) inversions+=l/2 - a;
      }
      else
      { z[k]=*(pstart + a); a++;
      }
    }
    for(k=0; k<l; k++)
    { *(pstart+k)=z[k];//copying. the linear work.
    }
  }
  else {}//base case: already sorted.
}
int main()
{   int t;
    cin>>t;
    while(t--)
    {   inversions=0;
        int n;
        cin>>n;
        int x[n];
        for(int i=0; i<n; i++)  cin>>x[i];
        mergesort(x, x+n);
        cout<<inversions<<'\n';
    }
    return 0;
}
