#include <iostream>
using namespace std;
int main()
{   int n, ans=0;
    cin >> n;
    bool c[n];
    for(int i = 0;i < n;i++)
    {  cin >> c[i];
    }
    for(int i=0; i<n; i++)
    {   if(c[i+2]&&(!c[i])){ans++;}
        else{ans++; i++;}
    }
    cout<<ans;
    return 0;
}

