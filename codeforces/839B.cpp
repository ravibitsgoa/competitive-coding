#include<iostream>
#include<vector>
using namespace std;
int main()
{   int n, k;
    cin>>n>>k;
    long long sum, i;
    vector<int> freq(9);
    for(int i=0; i<k; i++)
    {   int a;
        cin>>a;
        if(a>=8)
        {
            freq[8]+=8;
            a%=8;
        }
        freq[a]+=a;
    }
    sum+=8*n;
    int four=n, twos=n;
    int temp=min(freq[8]/2, four);
    sum-=(4*temp);
    freq[8]-=(4*temp);
    four-=temp;
    if(freq[8]==4)
    {   freq[4]+=4;
        freq[8]=0;
    }
    //freq[8]=0;
    temp=min(freq[4], four);
    sum-=(4*temp);
    freq[4]-=(4*temp);
    four-=temp;

    temp=min(freq[2], twos);
    sum-=2*temp;
    freq[2]-=temp;

    temp=min(freq[4], 2*twos);
    sum-=(4*temp);
    freq[4]-=(4*temp);
    twos-=2*temp;
    if(freq[4]==2)
    {   freq[2]+=2;
        freq[4]=0;
    }
    for(int i=1; i<4; i++)
    {   temp=min(freq[i]/i, freq[8-i]/(8-i));
        sum-=7*temp+1;
        freq[i]-=temp*i;
        freq[8-i]-=(8-i)*temp;
    }
    int count=0;
    for(int i=1; i<8; i++)
    {   count+=freq[i]/i;
        sum-=freq[i];
    }
    sum-=count;
    if(sum>=0)
        cout<<"no";
    else
        cout<<"yes";
    return 0;
}
