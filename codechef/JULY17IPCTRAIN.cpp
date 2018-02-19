#include<iostream>
#include<set>
#include<algorithm>
#define xx first
#define yy second
typedef unsigned long long ull;
using namespace std;
int main()
{ int T;
  cin>>T;
  while(T--)
  { ull N, D;
    cin>>N>>D;
    pair<ull, pair<ull, ull> > trainers[N];
    for(int i=0; i<N; i++)
      cin>>trainers[i].xx>>trainers[i].yy.xx>>trainers[i].yy.yy;

    sort(trainers, trainers+N);
    int j=0;//an index on trainers.
    set< pair<ull, ull >, std::greater<pair<ull,ull> > > haalma;//{sadness, index}.
    auto k=haalma.begin();
    ull ans=0;
    for(int i=1; i<=D; i++)
    { while(j!=N && trainers[j].xx <= i)
      { haalma.insert({trainers[j].yy.yy, j});
        j++;
      }
      if(haalma.size()>0)
      { k=haalma.begin();
        //cout<<k->xx<<' ';
        trainers[k->yy].yy.xx--;
        if(trainers[k->yy].yy.xx ==0)//Quota complete.
        { haalma.erase(k);
        }
        //cout<<ans<<endl;
      }
    }
    k=haalma.begin();
    while(haalma.size()>0 && k!=haalma.end())
    { ans+=(k->xx)*trainers[k->yy].yy.xx;
      k++;
    }
    cout<<ans<<'\n';
  }

  return 0;
}
