#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   long long n, x1, y1, x2, y2;
        cin>>n>>x1>>y1>>x2>>y2;
        if(min(y1, n+1-y1) > min(y2, n+1-y2))
            cout<<"Miron\n";
        else if(min(y1, n+1-y1) < min(y2, n+1-y2) )
            cout<<"Slava\n";
        else
            cout<<"Draw\n";
    }
    return 0;
}
