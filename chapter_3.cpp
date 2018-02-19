#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()// a program to find the longest and shortest string out of given 'x' strings.
{
    int x, minl, maxl;
    string a;
    cout<<"Enter no. of strings you want to enter\t";
    cin>>x;
    cin>>a;
    minl=a.length();
    maxl=a.length();
    while(--x)
    {   cin>>a;
        if(maxl<a.length())         {maxl=a.length();}
        else if(minl>a.length())    {minl=a.length();}
    }//This code has been optimized for memory, such that it does not need any vector.
    cout<<"\nmaximum "<<maxl<<" minimum "<<minl;
return 0;
}
