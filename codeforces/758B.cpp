#include<string>
#include<iostream>
using namespace std;
string x;
int r=0,g=0,b=0,y=0;
int flag[100]={0};
char at(int i)
{ flag[i]=1;
  if(x[i]=='!')
  { bool re,gr,bl,ye;
    re=gr=bl=ye=0;
    int e;
    for(int j=i-3; j<i+4; j++)
    { if(j>0 && j<x.size())
      { if(x[j]=='R') re=1;
        else if(x[j]=='G') gr=1;
        else if(x[j]=='B') bl=1;
        else if(x[j]=='Y') ye=1;
        else if (!flag[j]) {at(j); j--;}
      }
    }
    if(re==0)      {r++; flag[i]=0; x[i]='R';  return 'R';}
    else if(gr==0) {g++; flag[i]=0; x[i]='G';  return 'G';}
    else if(ye==0) {y++; flag[i]=0; x[i]='Y';  return 'Y';}
    else if(bl==0) {b++; flag[i]=0; x[i]='B';  return 'B';}
    else return -1;
  }
  return x[i];
}
int main()
{ cin>>x;
  r=g=b=y=0;
  for(int i=0; i<x.size(); i++)
  { if(x[i]=='!')
      at(i);
  }
  cout<<r<<' '<<b<<' '<<y<<' '<<g;
  return 0;
}
