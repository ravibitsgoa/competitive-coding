#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin>>n;
    set<pair<int, int> > A, B;
    
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
            swap(a, b);
        A.insert({a, b});
    }
    
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
            swap(a, b);
        B.insert({a, b});
    }
    
    int count=0;
    for(auto p : A)
    {
        if(B.find(p)!=B.end())
            count++;
    }
    cout << count;
}
