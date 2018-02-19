#include<iostream>
using namespace std;
int &swap(int &x)
{   return x;
}
int main()
{   int a=10;
    int &c=swap(a);
    c=50;
    cout<<c<<" "<<a;

return 0;
}
