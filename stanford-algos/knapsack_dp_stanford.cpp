//This implements a DP algorithm to solve the knapsack problem with integer capacities and weights.
// Algorithms-course/part3/week4/assignment/question1
#include<cstdio>
#include<algorithm>
using namespace std;
long long val[2001], w[2001], A[2][2000001]={0};//Values of A[0][x] are 0.
int main()
{ long long ksize, n;
  scanf("%lld %lld",&ksize,&n);
  for(int i=1; i<=n; i++)
    scanf("%lld %lld", &val[i], &w[i]);
  for(int i=1; i<=n; i++)
  { for(int x=0; x<=ksize; x++)
    { if(x>=w[i])
        A[1][x]=max(A[0][x], A[0][x-w[i]] + val[i]);
      else
        A[1][x]=A[0][x];
    }
    for(int x=0; x<=ksize; x++)
      A[0][x]=A[1][x];
  }
  printf("%lld\n",A[1][ksize]);
return 0;
}
