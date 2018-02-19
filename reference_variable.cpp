#include<iostream>
using namespace std;
void fun(int a, int &b)
{   a--; b++;
    return fun(a, b);
}
int main()
{   int x=5, y=0;
    fun(x, y);
    cout<<y;
}
