#include<iostream>
using namespace std;
int main()
{ int hh, mm;
  char ch;
  cin>>hh>>ch>>mm;
  int ans=0;
  while(1)
  { int dig1=hh/10, dig2=hh%10, dig3=mm/10, dig4=mm%10;
    if(dig1==dig4 && dig2==dig3)
    { cout<<ans;
      break;
    }
    mm++;
    ans++;
    if(mm==60)
    { hh++;
      mm=0;
    }
    if(hh==24)
      hh=0;
  }
return 0;
}
