#include<iostream>
using namespace std;
void quicksort(int p[], int l, int r, long long &ans)
{ if(r-l>1)
  { //choosing pivot
    int a=p[l], i=l+1;//first element is chosen.

    //partitioning.
    for(int j=l+1; j<r; j++)
    { if(p[j]<a)
      {int temp=p[j]; p[j]=p[i]; p[i]=temp; i++;}
    }
    ans+=r-l-1;
    int temp=p[l]; p[l]=p[i-1]; p[i-1]=temp;//partitioning done.

    quicksort(p, l, i-1, ans);
    quicksort(p, i, r, ans);
  }
  else {}//base case: already sorted.
}
int main()
{ int x[10000];
  long long int ans=0;
  for(int i=0; i<10000; i++)
    cin>>x[i];
  quicksort(x, 0, 10000, ans);
  cout<<ans<<endl;
  return 0;
}
