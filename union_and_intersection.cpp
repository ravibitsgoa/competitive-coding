#include<iostream>
using namespace std;
int main()
{   int a, b;
    cout<<"Enter no. of elements of the first and 2nd array\t";
    cin>>a>>b;
    long int A=0, B=0;
    while(a--)
    {   int x;
        cin>> x;
        A|=(1<<x);
    }
    while(b--)
    {   int y;
        cin>> y;
        B|=(1<<y);
    }
    long int uni = A | B;//this stores the union set.
    cout<<endl<<"Union of those sets is\n";
    for(int i=0; uni>0; i++)
    {   if(uni & (1<<i))
        {   cout<<i<<' ';
            uni-=(1<<i);
        }
    }
    return 0;
}
