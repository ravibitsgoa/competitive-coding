#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   string x;
        cin>>x;
        string y=x;
        int l=x.length()/2, r=l;
        l--;
        for(int i=0; i<x.length(); i++)
        {   if((i+x.length())%2==0 && l>=0)
                y[l--]=x[i];
            else 
                y[r++]=x[i];
        }
        cout<<y;
    }
	return 0;
}
