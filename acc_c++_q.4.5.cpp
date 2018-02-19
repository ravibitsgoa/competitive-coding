#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool compare(string &x, string &y)
{   return x<y;
}
int main()
{   vector<string> s;
    string x;
    int n=7;
    while(cin>>x && --n)
    {   s.push_back(x);
    }
    sort(s.begin(), s.end(), compare);
    int freq=1, i;
    for(i=1; i<s.size(); i++)
    {   if(s[i]==s[i-1]){freq++;}
        else{cout<<s[i-1]<<' '<<freq<<endl; freq=1;}
    }
    if(freq!=1)
    {   cout<<s[i-1]<<' '<<++freq;
    }
    return 0;
}
