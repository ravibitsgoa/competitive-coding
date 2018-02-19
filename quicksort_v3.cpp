#include<iostream>
using namespace std;
void quicksort(int p[], int l, int r, long long &ans)
{ if(r-l>1)
  { int h, a, i=l+1;
    //finding middle element
    if(r-l %2 ==0) h=l-1+(r-l)/2;
    else h=(r+l)/2;

    //choosing pivot:
    if((p[l]<p[r-1] && p[r-1]<p[h])||(p[l]>p[r-1] && p[r-1]>p[h]))
    { a=p[r-1]; //last element is chosen.
      p[r-1]=p[l]; p[l]=a;
    }
    else if((p[l]>p[r-1] && p[l]<p[h])||(p[l]<p[r-1] && p[l]>p[h]))
    { a=p[l]; //first element is chosen.
    }
    else
    { a=p[h]; //middle element is chosen.
      p[h]=p[l]; p[l]=a;
    }
    //partitioning done

    for(int j=l+1; j<r; j++)
    { if(p[j]<a)
      {int temp=p[j]; p[j]=p[i]; p[i]=temp; i++;}
    }
    ans+=r-l-1;
    int temp=p[l]; p[l]=p[i-1]; p[i-1]=temp;//partitioning done.

    quicksort(p, l, i-1, ans);
    quicksort(p, i, r, ans);
    /*for(int k=l; k<r; k++)
      cout<<p[k]<<' ';
    cout<<endl;*/
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
