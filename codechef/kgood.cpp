#include<iostream>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   string x;
        int K;
        cin>>x>>K;
        int freq[26]={0};
        for(int i=0; i<x.length(); i++)
            freq[x[i]-'a']++;
        int min_freq, ans=x.length();
        for(char d : x)
        {   min_freq = freq[d-'a'];
            int temp = 0;
            for(int i=0; i<26; i++)
            {   if(freq[i] > min_freq+K)
                    temp += freq[i] - min_freq -K;
                else if(freq[i] < min_freq)
                    temp += freq[i];
            }
            ans = min(ans, temp);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
