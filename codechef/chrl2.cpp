#include<iostream>
using namespace std;
int main()
{ string x;
  cin>>x;
  int len=x.length(), count=0;
  char stack[len], stacklen=0;
  for(int i=0; i<len; i++)
  { if(x[i]!='F' && (stacklen>0 && x[i]!=stack[stacklen-1]))
      stack[stacklen++]=x[i];
    else if(x[i]!='F' && (i==0 || x[i]=='C'))
      stack[stacklen++]=x[i];
    else if(x[i]=='F' && stacklen>0)
    { char c1=stack[stacklen-1], c2=stack[stacklen-2], c3=stack[stacklen-3];
      //cout<<c1<<c2<<c3;
      if(c1=='E' && c2=='H' && c3=='C')
      { count++;
        stacklen-=3;
      }
    }
  }
  cout<<count;
return 0;
}
