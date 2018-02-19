#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n], b[n], c[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
    {   cin>>b[i];
        c[i]=b[i];
    }
    sort(c, c+n);
    sort(a, a+n);
    reverse(a, a+n);

    map<int, vector<int> >chhe;
    for(int i=0; i<n; i++)
        chhe[c[i]].push_back(a[i]);
    for(int i=0; i<n; i++)
    {   cout<<chhe[b[i]].back()<<' ';
        chhe[b[i]].pop_back();
    }
    return 0;
}
