#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   string output;
        cin>>output;
        int q;
        cin>>q;

        int count=0;
        while(q--)
        {
            int output_freq[26]={0};
            for(int i=0; i<output.length(); i++)
            {   output_freq[output[i]-'a']++;
            }

            string input;
            cin>>input;
            int input_freq[26]={0};
            for(int i=0; i<input.length(); i++)
            {   input_freq[input[i]-'a']++;
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
