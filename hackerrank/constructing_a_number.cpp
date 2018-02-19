#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--)
    {   
        int n;
        cin>>n;
        unsigned long long sum=0, x;
        //cout << n<<' ';
        for(int i=0; i<n; i++)
        {   cin>>x;
            //cout << x<<' ';
            sum+=x;
        }
        if(sum%3)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}

