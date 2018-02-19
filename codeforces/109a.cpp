#include<iostream>
using namespace std;
int main()
{   int n, inp[1000], max, min, c=0;
    cin>>n;
    cin>>inp[0]; max=min=inp[0];
    for(int i=1; i<n; i++)
    {   cin>>inp[i];
    	if(inp[i]>max)      {max=inp[i]; c++;}
        if(inp[i]<min) 		{min=inp[i]; c++;}

    }
    cout<<c;
    return 0;

}
