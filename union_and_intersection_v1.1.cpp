#include<iostream>
using namespace std;
int main()
{   int a, b;
    cout<<"Enter no. of elements of the first and 2nd array\t";
    cin>>a>>b;
    long long uni=0; //this stores the union set.
    while(a--)
    {   int x;
        cin>> x;
        uni|=(1<<x);
    }
    while(b--)
    {   int y;
        cin>> y;
        uni|=(1<<y);
    }
    cout<<endl<<"Union of those sets is\n";
    for(int i=0; uni>0; i++)
    {   if(uni & (1<<i))
        {   cout<<i<<' ';
            uni-=(1<<i);
        }
    }
    return 0;
}
