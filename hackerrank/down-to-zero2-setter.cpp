#include <queue>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int dis[1000002];

int main()
{
    int n,que;
    cin>>que;
    while (que--)
    {
        cin>>n;
        if(n == 0)
        {
            cout<<0<<endl;
            continue;
        }
        queue<int> q;
        q.push(n);
        dis[n] = 1;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            if(dis[now-1] == 0)
            {
                dis[now-1] = dis[now]+1;
                if(now -1 == 0)
                    break;
                q.push(now-1);
            }
            for(int i = 2; i*i <= now; i++)
            {
                if(now%i == 0)
                {
                    int fac = max(i, now/i);
                    if(dis[fac] == 0)
                    {
                        dis[fac] = dis[now]+1;
                        q.push(fac);
                    }
                }
            }
        }
        cout<<dis[0]-1<<endl;
        memset(dis,0,sizeof(dis));
    }
    return 0;
}
