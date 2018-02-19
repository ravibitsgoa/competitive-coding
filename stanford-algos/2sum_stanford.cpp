#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>
#define size 1000000
using namespace std;
int main()
{ map<long long int,int> data;
  long long int x; //m=10000000000;
  for(int i=0; i<size; i++)
  { cin>>x;
    //if(i==0)
      //m=x;
   //if(x>0)
      //m=min(m,x);
    data[x]++;
  }
  //cout<<m;
  int ans=0;
  //for (long long int t=3; t<=10; t++)
  map<long long int, int> m;
  map<long long int, int>::iterator j, k;
  for(map<long long int,int>::iterator i=data.begin(); i->first<=10000 && i!=data.end(); i++)
  { //cout<<t<<" "<<i->first<<" "<<i->second<<endl;
    if(i->second>0)
    { j=data.lower_bound(-(i->first) - 10000);//lower_bound(i, data.end(), -(i->first) - 10000);
      //k=data.upper_bound(-(i->first) + 10000);//upper_bound(j, data.end(), -(i->first)+10000);
      //if (j!=data.end() && k!=data.end())
      while(j->first<= -(i->first)+10000 && j!=data.end())
      { if(m[j->first + i->first]==0)
        { ans++;
          m[j->first + i->first]=1;
        }
        j++;
      }
      //cout<<t<<i->first<<endl;
    }
  }
  cout<<ans;
return 0;
}
