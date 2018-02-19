#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<set<int> > graph(7);
        int last;
        cin>>last;
        n--;
        int ans=1;
        while(n--)
        {   int x;
            cin>>x;
            if(x==last)
            {   ans=-1;
                break;
            }
            graph.at(x).insert(last);
            graph.at(last).insert(x);
            last = x;
        }
        string answer = "0123456";
        if(ans==-1)
        {   cout<<"-1\n";
            continue;
        }
        ans=-1;
        do{
            int temp =0;
            for(int i=1; i<=6; i++)
            {
                if(answer.at(i) == '0')
                    temp=2;
                //cout<<answer[i]-'0';
                if((answer.at(i)-'0') == i)
                    temp =1;
                if(graph.at(i).find(answer.at(i)-'0') != graph.at(i).end())
                    temp=1;
            }
            if(temp==2)
                break;
            if(temp ==1)
                continue;
            for(int i=1; i<=6 && temp==0; i++)
                cout<<answer.at(i)<<' ';
            if(temp==0)
            {   ans=0;
                break;
            }
        } while(next_permutation(answer.begin(), answer.end()));
        if(ans==-1)
            cout<<-1;
        cout<<'\n';
    }
}
