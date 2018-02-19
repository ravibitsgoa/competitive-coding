#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>i, pair<int,int> j)
{   if(i.second < j.second)
        return true;
    if(i.second == j.second && i.first < j.first)
        return true;
    return false;
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {   int N;
        cin>>N;
        pair<int, int> intervals[N];
        for(int i=0; i<N; i++)
            cin>>intervals[i].first>>intervals[i].second;
        sort(intervals, intervals +N, comp);
        int thisEnd=0, index=0, ans=0;
        //vector<int> done(N, 0);
        for(; index<N;)
        {   ans++;
            thisEnd = intervals[index].second;
            index++;
            while(index<N && intervals[index].first <= thisEnd)
                index++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
