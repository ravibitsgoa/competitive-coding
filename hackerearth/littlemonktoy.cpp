#include <bits/stdc++.h>
using namespace std;
void fastscan(int &number)
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    fastscan(n);
    int in[n];
    for(int i=0; i<n; i++)
    {    fastscan(in[i]);
        //cout<<in[i];
    }
    sort(in,in+n);
    int sumlast=0, sum=0, level=0, last=0;
    for(int i=0; i<n;)
    {   sum=0;
        int j;
        for(j=0; sum<=sumlast && (i+j)<n; j++)
          sum+=in[i+j];
        //cout<<sum;
        while(j<last && (i+j)<n)
        { sum+=in[i+j];
          j++;
        }
        if(sum<=sumlast || j<last)
          break;
        level++;
        last=j+1;
        i+=j;
        cout<<sum<<endl;
        sumlast=sum;
    }
    cout<<level;
    return 0;
}
