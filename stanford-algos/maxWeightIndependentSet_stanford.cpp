/* A solution to
Algorithms-course/part3/week3/Assignment/question3
This implements dynamic programming to find max weight independent set for a input path graph.
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{ int N;
  scanf("%d",&N);
  long long W[N+1];           //one based indexing.
  for(int i=1; i<=N; i++)
    scanf("%lld",&W[i]);
  long long sum[N+1]={0};     //sum[i]= sum of max weight independent set of graph containing nodes [1:i].
  sum[1]=W[1];
  int selected[N+1]={0};//This is 1 if ith Node is selected in the maximum weight independent set.
  for(int i=2; i<=N; i++)
  { sum[i]=max(sum[i-1], sum[i-2]+ W[i]);
  }
  for(int i=N; i>1; i--)
  { if(sum[i-1]< sum[i-2]+W[i])
    { selected[i]=1;
      i--;
    }
  }
  if(!selected[2])
    selected[1]=1;
  int arr[]={1, 2, 3, 4, 17, 117, 517, 997};//For the required output.
  printf("%lld\n",sum[N]);
  for(int i : arr)
    printf("%d",selected[i]);
return 0;
}
