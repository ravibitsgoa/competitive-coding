#include<iostream>
using namespace std;
int main()
{ string x;
  cin>>x;
  //int vvv=0, vk=0, kk=0, ;
  int ans=0;
  bool done=1;
  for(int i=0; i<x.length()-1; i++)
  { if(x[i]=='V' && x[i+1]=='K')
    { ans++;
      i++;
    }
    else if(done && x[i]=='V' && x[i+1]=='V')
    { x[i+1]='K';
      done=0;
      ans++;
    }
    else if(done && x[i]=='K' && x[i+1]=='K')
    { x[i]='V';
      done=0;
      ans++;
    }
    /*if(x[i]=='V' && x[i+1]=='V' && x[i+2]=='V')
      vvv++;
    else if(x[i]=='V' && x[i+1]=='K')
      vk++;
    else if(x[i]=='K' && x[i+1]=='K')
      kk++;*/
  }
  //ans+=(vv>0)||(kk>0);
  cout<<ans;
return 0;
}
