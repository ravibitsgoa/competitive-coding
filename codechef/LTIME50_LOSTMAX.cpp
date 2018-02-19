#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int k;
        vector<int> num;
        char c=' ';
        while(c!='\n')
        {   scanf("%d%c",&k,&c);
            num.push_back(k);
        }
        sort(num.begin(), num.end());
        if(num[num.size()-1] != num.size()-1)
        {   cout<<num[num.size()-1]<<'\n';
        }
        else
        {   cout<<num[num.size()-2]<<'\n';
        }
    }
    return 0;
}
