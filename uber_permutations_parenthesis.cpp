#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;

//unordered_set<string> paran;
const int NMAX = 200;
unsigned long long count[NMAX][NMAX]={0};
//unordered_set<string> incomplete;

unsigned long long F(string s, int rem_start, int rem_end, int on_stack)
{   
    if(count[rem_start][rem_end]!=0)
        return count[rem_start][rem_end];
    long long ans=0;
    if(on_stack == 0 && rem_start!= rem_end)
        assert(0); //invalid string s.
    if(on_stack == 0 && rem_start == 0 && rem_end == 0)
    {   //paran.insert(s);
        return 1;
    }
    if(on_stack > 0 && rem_end > 0)
        ans+= F(s+'}', rem_start, rem_end-1, on_stack-1);
    if(rem_start>0)
        ans+= F(s+"{", rem_start-1, rem_end, on_stack+1);
    count[rem_start][rem_end]= ans;
    return ans;
}

void generate_all_valid_permutations(int n)
{
    cout << F("", n, n, 0) << endl;
}

int main()
{   
    int n;
    cin>>n;
    generate_all_valid_permutations(n);
    //cout << paran.size();
    //for(string s: paran)
    //    cout << s<<endl;
}
