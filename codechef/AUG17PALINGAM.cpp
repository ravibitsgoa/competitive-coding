#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   string a, b;
        cin>>a>>b;
        int f1[26]={0}, f2[26]={0};
        for(int i=0; i<a.length(); i++)
            f1[a[i]-'a']++;
        for(int i=0; i<b.length(); i++)
            f2[b[i]-'a']++;
        int ans=1, rep=0;
        for(int i=0; i<26; i++)
        {   if(f1[i]!=0 && f2[i]==0)
                ans=0;
            if(f1[i]>1 && f2[i]==0)
                rep=1;
        }
        if(ans)
            cout<<"B\n";
        else if(rep)
            cout<<"A\n";
        else
        {   ans=1;
            for(int i=0; i<26; i++)
            {   if(f1[i]==0 && f2[i]!=0)
                    ans=0;
            }
            if(ans)
                cout<<"A\n";
            else
                cout<<"B\n";
        }
    }
    return 0;
}
