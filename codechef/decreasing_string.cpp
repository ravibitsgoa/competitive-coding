#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int k;
        cin>>k;
        char x= 'a'+ (k%25);
        while(x>'a')
        {   cout<<x; if(x=='b') cout<<'a';
            x--;
        }
        k-=(k%25);
        k/=25;
        for(int i=0; i<k; i++)
        {   cout<<"zyxwvutsrqponmlkjihgfedcba";
        }
        cout<<endl;
    }
    return 0;
}
