#include<iostream>
using namespace std;
int n, s;
int x[100005], v[100005];
double tmin(int pos)
{ //double t = (x[0]-pos) / ((double)s-v[0]);
  //if(t<0) t*=-1;

  for(int i=1; i<n; i++);

}
int main()
{ cin>>n>>s;
  for(int i=0; i<n; i++)
  { cin>>x[i]>>v[i];
    int d;
    cin>>d;
    if(d==1)
      v[i]=-v[i];
  }

  return 0;
}
