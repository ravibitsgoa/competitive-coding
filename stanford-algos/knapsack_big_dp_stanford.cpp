//This implements a DP algorithm to solve the knapsack problem with integer capacities and weights.
// Algorithms-course/part3/week4/assignment/question1
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
long long val[2005]={0}, w[2005]={0}, sumw[2005]={0}, sumv[2005]={0};
map<pair<long long, long long>, long long> ans;
long long f(long long n, long long size)
{ if(n==0)
    return 0;
  if(ans[{n, size}])
    return ans[{n, size}];
  if(sumw[n]<=size)
    return ans[{n, size}]=sumv[n];
  if(!ans[{n-1, size}])
    ans[{n-1, size}]=f(n-1, size);
  if(w[n]>size)
    return ans[{n, size}]=ans[{n-1,size}];
  if(!ans[{n-1, size-w[n]}])
    ans[{n-1, size-w[n]}] = f(n-1, size-w[n]);
  return ans[{n, size}]=max(ans[{n-1, size}], val[n]+ans[{n-1, size-w[n]}] );
}

int main()
{ long long ksize, n;
  scanf("%lld %lld",&ksize,&n);
  for(int i=1; i<=n; i++)
  { scanf("%lld %lld", &val[i], &w[i]);
    sumw[i]=sumw[i-1]+w[i];
    sumv[i]=sumv[i-1]+val[i];
  }
  ans.clear();
  printf("%lld\n",f(n, ksize));
return 0;
}
