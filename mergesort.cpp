#include<iostream>
using namespace std;
void mergesort(int p[], int i, int l)
{ if(l>1)
  { mergesort(p, i, l/2);
    mergesort(p, i+(l/2), l-(l/2));
    int z[l], k, a=0, b=0;
    for(k=0; k<l; k++)
    { if(p[i+a]<=p[i+(l/2)+b] && a<l/2)  {z[k]=p[i+a]; a++;}
      else if(b<l-(l/2))                 {z[k]=p[i+(l/2)+b]; b++;}
      else {z[k]=p[i+a]; a++;}
    }
    for(int k=0; k<l; k++)
    { p[i+k]=z[k];//copying. the linear work.
    }
  }
  else {}//base case: already sorted.
}
int main()
{ int x[10]={5,9,4,9,1,0,16,4,5,2};
  mergesort(x, 0, 10);
  for(int i=0; i<10; i++)
    cout<<x[i]<<' ';
  cout<<endl;
  return 0;
}
//completed on 10th Dec 2016, 6:15 PM
