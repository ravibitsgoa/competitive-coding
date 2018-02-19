#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin>>n>>k;
    int q[k]={0};
    int count=0, s[n];
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
        q[s[i]%k]++;
    if(q[0]>0)
        count++;
    //cout<<q[0];
    for(int i=1; i<k/2 + (k%2); i++)
    {   if(q[i]>=q[k-i])
            count+=q[i];
        else
            count+=q[k-i];
        //cout<<q[i]<<' '<<q[k-i]<<endl;
    }
    if(k%2==0 && q[k/2]>0)
      count++;
    cout<<count;
    return 0;
}
