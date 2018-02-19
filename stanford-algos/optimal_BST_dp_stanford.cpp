//This implements optimal BST with a DP algorithm.
// Algorithms-course/part3/week4/quiz
#include<iostream>
using namespace std;
float w[]={0, 0.2, 0.05, 0.17, 0.1, 0.2, 0.03, 0.25};
const int n=7;
float sums[]={0, 0.2, 0.25, 0.42, 0.52, 0.72, 0.75, 1.00};
float A[n+1][n+1]={0};
float sum(int index)
{ if(index>=n)      return 1.00;
  else if(index<=0) return 0.00;
  else              return sums[index];
}
int main()
{ for(int s=0; s<n; s++)
  { for(int i=1; i<=n; i++)
    { A[i][i+s]=sum(i+s)-sum(i-1)+A[i+1][i+s];
      for(int r=i+1; r<i+s; r++)
        A[i][i+s]=min(A[i][i+s], sum(i+s)-sum(i-1) + A[i][r-1] + A[r+1][i+s]);
      A[i][i+s]=min(A[i][i+s], sum(i+s)-sum(i-1) +A[i][i+s-1]);
    }
  }
  cout<<A[1][n];
return 0;
}
