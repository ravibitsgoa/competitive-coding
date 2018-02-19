#include<iostream>

using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int arr[26];
        for(int i=0; i<26; i++)
            cin>>arr[i];
        string x;
        cin>>x;
        for(char c : x)
            arr[c-'a']=0;
        long long sum=0;
        for(int i=0; i<26; i++)
            sum+=arr[i];
        cout<<sum<<'\n';
    }
    return 0;
}
