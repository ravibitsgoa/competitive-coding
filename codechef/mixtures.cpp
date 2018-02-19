#include<iostream>
#include<map>
using namespace std;
int main()
{ int n, x;
  while(scanf("%d",&n)!=EOF && n!=0)
  { //map<int,bool> mixtures;
    int mixtures[100]={0};
    //while(n--)
    for(int j=0; j<n; j++)
    { cin>>x;
      mixtures[x]=1;
    }
    bool flag=0; //This flag indicates whether it's possible to find a pair that gives 0 as output colour.
    int smoke=0; //This is the answer. the total smoke produced by mixing.
    //map<int,bool>::iterator i;
    //int i;
    while(n-- >1)
    { int first=-1, second=-1;
      for(int i=0; i<100; i++)
      { //cout<<i->first;
        if(mixtures[i]==1 && first==-1)
          first=i;
        else if(mixtures[i]==1 && second==-1)
          second=i;
        if(mixtures[i]==1 && mixtures[100-i]==1)
        { flag=1;
          smoke=i*(100-i);
          cout<<smoke<<endl;
          break;
        }
      }
      if(flag==1)
        break;
      smoke+=first*second;
      mixtures[first]=0;
      mixtures[second]=0;
      mixtures[(first+second)%100]=1;
    }
    if(flag!=1)
    cout<<smoke<<endl;
  }
  return 0;
}
