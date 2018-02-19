#include<iostream>
#include<cmath>
using namespace std;

int main()
{   int t;
    cin>>t;
    while(t--)
    {   double N, v1, v2;
        cin>>N>>v1>>v2;
        if(2.0/v2 <  sqrt(2)/v1)
            cout<<"Elevator"<<'\n';
        else
            cout<<"Stairs\n";
    }
    return 0;
}
