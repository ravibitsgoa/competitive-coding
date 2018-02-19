#include<string>
#include<iostream>
using namespace std;
int main()
{ string x,y;
  cin>>x>>y;
  bool inverse=0;
  if(x.length()<y.length())
  { string z=y;
    y=x;
    x=z;
    inverse=1;
  } //Making x the longer string.
  int i, lx=x.length(), ly=y.length();
  for(i=0; i<lx; i++)
  { if(x[i]=='1' && ((ly-lx+i)>=0) && y[(ly-lx+i)]=='1')//This checks if same powers of q in x and y, are present (1).
    { x[i]=y[(ly-lx+i)]='0';
    }
    else if(x[i]=='1' && (((ly-lx+i+1)>=0)) && y[ly-lx+i+1]=='1' && y[ly-lx+i+2]=='1')//This checks if q^2 is present in x and q+1 is present in y.
    {  x[i]=y[(ly-lx+i+1)]=y[(ly-lx+i+2)]='0';
    }
    else if(x[i]=='1')
    { if(inverse==0)  cout<<">";
      else            cout<<"<";
      break;
    }
    else if(x[i]=='0' && ((ly-lx+i)>=0) && y[(ly-lx+i)]=='1')
    { if(inverse==0)  cout<<"<";
      else            cout<<">";
      break;
    }
    else if(x[i]=='0' && ((ly-lx+i+1)>=0) && (y[(ly-lx+i+1)]=='1' && y[ly-lx+i+2])=='1')
    { if(inverse==0)  cout<<"<";
      else            cout<<">";
      break;
    }
  }
  if(i==lx)
    cout<<"=";
  return 0;
}
