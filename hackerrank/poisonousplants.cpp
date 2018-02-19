#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int currentinput, lastinput=0, laststable=0;
  cin>>currentinput;
  laststable=currentinput;
  lastinput=currentinput;
  n--;
  int curr_days=0, maxdays=0;
  while(n--)
  { cin>>currentinput;
    if(currentinput < laststable)
    { laststable= currentinput;
      maxdays=max(maxdays,curr_days);
      curr_days=0;
    }
    else if((currentinput < lastinput && curr_days>0) || (currentinput > lastinput && curr_days==0))
      curr_days++;
    lastinput=currentinput;
    //cout<<curr_days<<' '<<lastinput<<'\n';
  }
  maxdays=max(maxdays,curr_days);
  cout<<maxdays;
return 0;
}
