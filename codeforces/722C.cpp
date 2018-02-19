#include<set>
#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int a[n+1]={0};
  for(int i=1; i<=n; i++)
    cin>>a[i];
  int seq[n+1]={0};
  for(int i=1; i<=n; i++)//one based indexing everywhere.
    cin>>seq[i];
  int ans[n+1];
  bool destroyed[n+1]={0};
  multiset<int> sums;
  int sum_till_this_element[n+1]={0};
  sums.insert(0);
  for(int i=n; i>=1; i--)
  { ans[i]=*sums.rbegin();
    destroyed[seq[i]]=1;
    if(seq[i]==n)
    { sum_till_this_element[n]=sum_till_this_element[n-1]+a[n];
      if(sum_till_this_element[n-1])
        sums.erase(sum_till_this_element[n-1]);
      sums.insert(sum_till_this_element[n]);
    }
    else //if(destroyed[a[i]+1] && destroyed[a[i]-1])
    { sum_till_this_element[seq[i]]=sum_till_this_element[seq[i]-1]+sum_till_this_element[seq[i]+1]+a[seq[i]];
      if(sum_till_this_element[seq[i]-1])
        sums.erase(sum_till_this_element[seq[i]-1]);
      if(sum_till_this_element[seq[i]+1])
        sums.erase(sum_till_this_element[seq[i]+1]);
      sums.insert(sum_till_this_element[seq[i]]);
    }
  }
  for(int i=1; i<=n; i++)
    cout<<ans[i]<<'\n';
return 0;
}
