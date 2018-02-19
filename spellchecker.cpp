#include<iostream>
#include<string>
using namespace std;
string dict[10]={"Apple","Cat","Deed","Elephant","Finally","Good","High","Ideal","Jack","Queen"};
int exists(string inp, int i, int f)
{   //cout<<i<<' '<<f<<endl;
    if(dict[(i+f)/2]==inp)  return 1;//return (i+f)/2;
    else if(f<i+2)          return 0;
    else if(dict[(i+f)/2][0]<inp[0])    return exists(inp, (i+f)/2, f);
    else                                return exists(inp, i, (i+f)/2);
}
int main()
{   cout<<exists("Hello",0,10)<<endl;
return 0;
}
