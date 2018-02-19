#include<iostream>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {   string output;
        cin>>output;
        int q;
        cin>>q;

        int output_freq[26]={0};
        for(char i : output)
        {   output_freq[i-'a']++;
        }

        int count=0;
        while(q--)
        {
            string input;
            cin>>input;
            int input_freq[26]={0};
            for(char i : input)
            {   input_freq[i-'a']++;
            }
            bool ans=1;
            for(int i=0; i<26; i++)
            {   if(input_freq[i] != output_freq[i])
                    ans=0;
            }
            if(ans)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
