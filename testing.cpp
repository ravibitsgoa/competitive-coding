#include<iostream>
using namespace std;
int &add10(int &x)
{ //return (x)+10;
  x+=10;
  return x;
}
int main()
{ int x=10, &y=x;
  cout<<x<<' '<<&x;
  cout<<endl<<y<<endl;
  cout<<&y;
  return 0;

}
