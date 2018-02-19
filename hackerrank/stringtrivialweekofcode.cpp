#include<iostream>
using namespace std;
string x(3,'a');
int n=3;
void increment(int i)
{ if(i<0)
    return;
  if(x[i]=='a'|| x[i]=='e' || x[i]=='i' || x[i]=='o'||x[i]=='u')
  { switch(x[i])
    { case 'a': x[i]='e'; break;
      case 'e': x[i]='i'; break;
      case 'i': x[i]='o'; break;
      case 'o': x[i]='u'; break;
      case 'u': {string y=x; increment(i-1); if(x!=y) {x[i]='a';} else {return;} break;}
    }
  }
  else
  { if(x[i]!='d' && x[i]!='h' && x[i]!='n' && x[i]!='t' && x[i]!='z')
      x[i]++;
    else if(x[i]=='d' || x[i]=='h' || x[i]=='n' || x[i]=='t')
      x[i]+=2;
    else  //i.e. x[i]=='z'
    { string y=x;
      increment(i-1);
      if(y!=x)
        x[i]='b';
      else
        return;
    }
  }
  if(i==n-1)
  { cout<<x<<endl;
    increment(n-1);
  }
  else
  return;
}
int main()
{ char vowels[5]={'a','e','i','o','u'}, consonents[20]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  int i;
  for(i=1; i<n; i+=2)
  { x[i]='b';
  }
  cout<<x<<endl;
  //increment(n-1);
  i=n-1;
  increment(n-1);
  for(i=0; i<n; i++)
  { if(i%2==0)
      x[i]='b';
    else
      x[i]='a';
  }
  cout<<x<<endl;
  increment(n-1);
  return 0;
}
