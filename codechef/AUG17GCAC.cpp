#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {   int n, m;
        cin>>n>>m;
        ll minS[n];
        for(int i=0; i<n; i++)
            cin>>minS[i];
        pair<pair<ll, ll>, int> company[m];
        for(int i=0; i<m; i++)
        {   cin>>company[i].first.first>>company[i].first.second;   //salary, job offers.
            company[i].second=i;                                    //original index.
        }
        char qual[n][m];
        for(int i=0; i<n; i++)
        {   for(int j=0; j<m; j++)
            {   cin>>qual[i][j];
            }
        }
        int passed=0, backComp=0;
        ll sum=0;
        sort(company, company+m);
        reverse(company, company+m);
        //best company will be in the beginning.
        int atleastOne[m]={0};
        for(int i=0; i<n; i++)
        {   for(int j=0; j<m; j++)
            {   if(qual[i][company[j].second]=='1' && company[j].first.second>0 && company[j].first.first>=minS[i] )
                {   //cout<<company[j].first.first<<'\n';
                    passed++;
                    atleastOne[company[j].second]=1;
                    (company[j].first.second)--;
                    sum+=company[j].first.first;
                    //cout<<company[j].second<<' ';
                    break;
                }
            }
        }
        for(int i=0; i<m; i++)
        {   //cout<<atleastOne[i];
            if(atleastOne[i]!=1)
                backComp++;
        }
        cout<<passed<<' '<<sum<<' '<<backComp<<'\n';
    }
    return 0;
}
