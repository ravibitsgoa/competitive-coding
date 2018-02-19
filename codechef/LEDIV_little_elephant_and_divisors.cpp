#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{   if(a==0)        return b;
    else if(b==0)   return a;
    else if(a>b)    return gcd(a%b, b);
    else return gcd(a, b%a);
}
int primes[72]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353};
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int ans, a;
        cin>>a;
        ans=a;
        n--;
        while(n--)
        {   cin>>a;
            if(ans>1)
                ans=gcd(ans, a);
        }
        if(ans!=1)
        {   int i;
            for(i=0; primes[i]!=353; i++)
            {   if(ans%primes[i]==0)
                {   cout<<primes[i]<<'\n';break;
                }
            }
            if(primes[i]==353)
                cout<<ans<<'\n';
        }
        else
            cout<<-1<<'\n';
    }
    return 0;
}
