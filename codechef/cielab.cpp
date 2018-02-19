#include<iostream>
using namespace std;
int main()
{   int a, b, d;
    cin>>a; cin>>b;
    d=a-b;
    cout<<(d+(d%10<9));
return 0;
}
