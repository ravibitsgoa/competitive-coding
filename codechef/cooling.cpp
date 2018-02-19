#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

void scan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scan(t);
    while(t--)
    {   int n;
        scan(n);
        int w[n], l[n], ans=0;
        for(int i=0; i<n; i++)
            scan(w[i]);
        for(int j=0; j<n; j++)
            scan(l[j]);
        sort(w, w+n);
        sort(l, l+n);
        for(int i=0, j=0; j<n; j++)
        {   if(l[j]>=w[i])
            {   i++;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
