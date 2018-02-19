#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
int main()
{
    ll lo=3, hi=6;
    ll count=0;
    for(ll i=1; i<sqrt(hi); i++)
    {   count+= 2*(ll)(hi/i);
        cout<<i<<' '<<2*(ll)(hi/i)<<endl;
    }
    cout<<count<<'\n';
    //if(((ll)sqrt(hi)*(ll)sqrt(hi)) == hi)
        //count++;
    for(ll i=1; i<sqrt(lo-1); i++)
        count-= 2*(ll)((lo-1)/i);
    //if(((ll)sqrt(lo)*(ll)sqrt(lo)) == lo)
        //count--;
    cout<<count;
    
}
