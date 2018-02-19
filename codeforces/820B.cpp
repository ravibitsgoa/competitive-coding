#include<cmath>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
const double PI=3.14159265359;
int main()
{ int n, angle;
  cin>>n>>angle;
  pair<double, double> coors[n];
  for (int i = 0; i < n; i++)
    coors[i]={ cos(2 * PI * i / (double)n), sin(2 * PI * i /(double) n)};
  double angles[n-1];

  for(int i=1; i<n; i++)
    angles[i-1]=atan( coors[i].second / (coors[i].first-1));
  for(int i=1; i<n; i++)
    angles[i]-=angles[0];

  int mi=360, ans=0;
  bool kari=0;
  for(int i=1; i<n; i++)
    if(mi> abs(angles[i]-angle))
    { mi=abs(angles[i]-angle);
      ans=i;
    }
  pair<int,int> finalans;
  for(int i=1; i<n; i++)
  { auto x= lower_bound(angles, angles+n-1, angles[i]+angle);
    auto y= upper_bound(angles, angles+n-1, angles[i]+angle);
    if(abs(*x - angles[i]) < mi)
    { kari=1;
      mi=abs(angles[i]- *x);
      finalans={i, x-angles};
    }
    if(abs(*y - angles[i]) < mi)
    { kari=1;
      mi=abs(angles[i]- *y);
      finalans={i, y-angles};
    }
  }
  if(kari)
    cout<<finalans.first+1<<" 1 "<<finalans.second+1;
  else
    cout<<"2 1 "<<ans+2;
return 0;
}
