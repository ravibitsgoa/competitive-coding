//practise : greedy
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <random>
#include <cassert>
using namespace std;
int main()
{   int N;
    scanf("%d",&N);
    N*=3;
    long long arr[N];
    long long sum=0;
    unordered_map<long long, vector<int> > valIndex;
    valIndex.clear();
    for(int i=0; i<N; i++)
    {   scanf("%lld",&arr[i]);
        sum+=arr[i];
        valIndex[arr[i]].push_back(i);
    }
    sum*=3;
    sum/=N;
    //printf("%lld\n",sum);
    int done[N]={0};
    int triple=0;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, N-1);
    vector<vector<int> > ans;
    for(int i=0; i<N/3; i++)
    {   int x=distribution(generator), y=distribution(generator);
        while(done[x])
            x=distribution(generator);
        while(done[y] || y==x)
            y=distribution(generator);

        long long val = sum - arr[x] - arr[y];
        for(int z=0; z<valIndex[val].size(); z++)
        {   if(!done[valIndex[val][z]] && valIndex[val][z]!=x && valIndex[val][z]!=y)
            {   done[x]=1;
                done[y]=1;
                done[valIndex[val][z]]=1;
                triple++;
                ans.push_back({x, y, valIndex[val][z]});
                break;
            }
        }
    }
    assert(triple == ans.size());
    printf("%d\n",triple);
    for(int i=0; i<ans.size(); i++)
    {   printf("%d %d %d ",ans[i][0]+1, ans[i][1]+1, ans[i][2]+1);
        assert(ans[i][0] != ans[i][1]);
        assert(ans[i][0] != ans[i][2]);
        assert(ans[i][1] != ans[i][2]);
        assert(arr[ans[i][0]] + arr[ans[i][1]] + arr[ans[i][2]] ==sum);
    }
    return 0;
}
