#include<iostream>
using namespace std;
int main()
{   int t; string s;
    cin>>t;
    while(t--)
    {   cin>>s;
        int i, freq[26]={0}, len=s.length();
        for(i=0; i<len/2; i++)
        {   freq[s[i]-97]++;
        }
        if(len%2)
        {   i++;
        }
        for(; i<len; i++)
        {   freq[s[i]-97]--;
        }
        for(i=0; i<26; i++)
        {   if(freq[i])
            {   cout<<"NO"<<endl;
                break;
            }
        }
        if(i==26)
        {   cout<<"YES"<<endl;
        }
    }
    return 0;
}
