#include<iostream>
using namespace std;
int main()
{ char stck[100000];
  int pos[100000];
  int j=0;
  string x;
  cin>>x;
  for(int i=0; i<x.length(); i++)
  { if(x[i]=='{' || x[i]=='[' || x[i]=='(')
    { stck[j]=x[i];
      pos[j]=i+1;
      j++;
    }
    else if(x[i]=='}' && stck[j-1]!='{')
    { cout<<i+1<<endl;
      return 0;
    }
    else if(x[i]==')' && stck[j-1]!='(')
    { cout<<i+1<<endl;
      return 0;
    }
    else if(x[i]==']' && stck[j-1]!='[')
    { cout<<i+1<<endl;
      return 0;
    }
    else if((x[i]==']' && stck[j-1]=='[') || (x[i]==')' && stck[j-1]=='(') || (x[i]=='}' && stck[j-1]=='{'))
      j--;
  }
  if(j!=0)
  { cout<<pos[j-1];
  }
  else
    cout<<"Success";
return 0;
}
