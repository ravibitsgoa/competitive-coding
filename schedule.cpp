#include<bits/stdc++.h>
using namespace std;
int main()
{ int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--)
  { int n, k;
    cin>>n>>k;
    string sche;
    cin>>sche;
    map<int,int> substring;
    for(int i=0; i<n;)
    { int j=i;
      while(i<n && sche[i]==sche[j])
      { i++;
      }
      substring[i-j]++;
      //cout<<i-j;
    }
    //cout<<endl;
    map<int,int> :: reverse_iterator i=substring.rbegin();
    while(k>0)
    { //cout<<i->first<<i->second;
      while(i->second==0)
        i++;
      //cout<<i->first<<i->second<<endl;
      if(i->first<=2 && i->second>0)
        break;
      if(i->second>0)
      { (i->second)--;
        k--;
        if(i->first %2 ==0)
        { substring[(i->first)/2]++;
          substring[1]++;
          substring[((i->first)/2) -1]++;
        }
        else
        { substring[(i->first)/2]+=2;
          substring[1]++;
        }
      }
      //cout<<"hello";
    }
    while(i->second==0)
      i++;
    cout<<i->first<<'\n';
  }
  return 0;
}
