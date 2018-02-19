#include<iostream>
using namespace std;
int maxj(int arr[10], int i, int j)
{ if(j-i>1)
  { if((arr[(i+j)/2]>arr[(i+j)/2 -1])&&(arr[(i+j)/2]<arr[(i+j)/2 +1]))
    { return maxj(arr, (i+j)/2, j);
    }
    else if((arr[(i+j)/2]<arr[(i+j)/2 -1])&&(arr[(i+j)/2]>arr[(i+j)/2 +1]))
    { return maxj(arr, i, (i+j)/2);
    }
    else return (i+j)/2;
  }
  else
   return i;
}
int max(int arr[10][10], int x, int y)
{ int j=maxj(arr[5], 0, 10), i;
  for(i=0; i<10 && arr[i+1][j]>arr[i][j]; i++)
  { }
  return arr[i][j];
}
int main()
{ int a[10][10], n=10, m=10, i, j;
  for(int i=0; i<n; i++)
  { for(int j=0; j<n; j++)
    { cin>>a[i][j];
    }
  }
  int mx=max(a, 10, 10);
  cout<<mx;
  return 0;
}
