#include <iostream>
#include <map>
using namespace std;

bool DFS(map<int, int> & explored, map<int, int> &stat, int s, int curr) //start vertex s.
{   explored[curr]=1;
    //cout<<curr<<' ';
    if(curr == -s)
        return 0;
    if(stat[curr]!=0 && !explored[stat[curr]])
        return DFS(explored, stat, s, stat[curr]);
    else
        return 1;
}

int main()
{
    int n;
    while(cin>>n && n!=0)
    {   map<int, int> stat;
        bool ans=1;
        for(int i=1; i<=n; i++)
        {   int index;
            string s;
            cin>>index>>s;

            if(s=="false")
            {   stat[i]= -index;
                if(stat[index]==0 || stat[index] == -i)
                    stat[index] = -i;
                else
                    ans = 0;
            }
            else
            {
                stat[i]= index;
                if(stat[-index] == 0 || stat[-index] == -i)
                    stat[-index] = -i;
                else
                    ans=0;
            }
        }
        for(int i=1; i<=n; i++)
        {   map<int, int> explored;
            explored.clear();
            if(stat[i] == i){}
            else
                ans *= DFS(explored, stat, i, i);
            //cout<<ans<<endl;
            //cout<<endl;
        }
        if(ans == 0)
            cout<<"PARADOX"<<endl;
        else
            cout<<"NOT PARADOX"<<endl;
    }
}
