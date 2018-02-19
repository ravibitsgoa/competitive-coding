#include<algorithm>
#include<utility>
#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  pair<int,int> exams[n];
  for(int i=0; i<n; i++)
    cin>>exams[i].first>>exams[i].second;
  sort(exams, exams+n);
  int currdate=min(exams[0].first, exams[0].second);
  for(int i=1; i<n; i++)
  { int x=exams[i].first, y=exams[i].second;
    if((x>=currdate && x<=y) || (y<currdate))
      currdate=x;
    else
      currdate=y;
  }
  cout<<currdate;
return 0;
}
