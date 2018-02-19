#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(int j, int unmatched, vector<int> &answer, vector<vector<int> > &graph)
{
    if(j>6 || j<=0)
        return 1;
    if(answer.at(j)!=0)
        return f(j+1, unmatched, answer, graph);
    for(int i=1; i<=6; i++)
    {   if(answer.at(i)!=0)
            continue;
        if(j!=i && graph.at(j).at(i)==0)
        {   answer.at(j)=i;
            answer.at(i)=j;
            if(f(j+1, unmatched-2, answer, graph))
                return 1;
            else
            {   answer.at(i)=0;
                answer.at(j)=0;
            }
        }
    }
    if(unmatched == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > graph(7, vector<int>(7, 0));
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
            graph.at(x).at(last)=1;
            graph.at(last).at(x)=1;
            last = x;
        }
        if(ans==-1)
        {   cout<<"-1\n";
            continue;
        }
        vector<int> answer(7,0);
        if(f(1, 6, answer, graph))
        {   for(int i=1; i<=6; i++)
                cout<<answer.at(i)<<' ';
        }
        else
            cout<<-1;
        cout<<'\n';
    }
}
