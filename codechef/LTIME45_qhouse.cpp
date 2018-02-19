#include<iostream>
using namespace std;
int x, y;
int bs(int x1, int y1, int x2, int y2)
{ cout<<"? "<<(x1+x2)/2<<' '<<(y1+y2)/2<<endl;
  string a;
  cin>>a;

  //cout<<x1<<y1<<x2<<y2<<endl;
  if(a=="YES" && x2-x1<=1 && y2-y1<=1)
  { cout<<"? "<<x2<<' '<<y2<<endl;
    cin>>a;
    if(a=="YES")
    { x=x2;
      y=y2;
    }
    else
    { x=(x1+x2)/2;
      y=(y1+y2)/2;
    }
    //cout<<x1<<y1<<x2<<y2<<endl;
    return 0;
  }
  else if(a=="YES")
  { bs((x1+x2)/2, (y1+y2)/2, x2, y2);
  }
  else
    bs(x1,y1,(x1+x2)/2,(y1+y2)/2);
}
int main()
{ int lsq=0, htr=0, btr=0, area=0;//lsq is length of square. htr is height of triangle, btr is base of triangle.
  bs(0, 0, 1000, 0);
  lsq=2*x;
  bs(0,0,0,1000);
  htr=y-lsq;
  bs(0,lsq,1000,lsq);
  btr=x;
  area=lsq*lsq;
  area+=htr*btr;
  cout<<lsq<<endl<<htr<<endl<<btr<<endl;
  cout<<"! "<<area;
return 0;
}
