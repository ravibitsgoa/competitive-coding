/* A solution to
Algorithms-course/part3/week3/Assignment/question1
This implements huffman's greedy coding algorithm.
*/
#include<cstdio>
#include<set>
#include<vector>
#include<utility>
using namespace std;
int main()
{ int NumSymbols;
  scanf("%d",&NumSymbols);
  long long W[NumSymbols];
  set<pair<int, vector<int> > >  symbols;
  for(int i=0; i<NumSymbols; i++)
  { scanf("%lld",&W[i]);
    symbols.insert({W[i], {i}});
  }
  int codeLength[NumSymbols]={0};
  while(symbols.size()>1)
  { auto i = symbols.begin(), j=i;
    j++;
    long long new_weight=i->first  + j->first;
    for(int k : i->second)
    { codeLength[k]++;
    }
    for(int  k : j->second)
    { codeLength[k]++;
    }
    vector<int>new_vector(i->second);
    new_vector.reserve(new_vector.size() + (j->second).size());
    new_vector.insert(new_vector.end(), j->second.begin(), j->second.end());
    symbols.erase(symbols.begin());
    symbols.erase(symbols.begin());
    symbols.insert({new_weight, new_vector});
  }
  int maxl=0, minl=NumSymbols;
  for(int i=0; i<NumSymbols; i++)
  { maxl=max(maxl, codeLength[i]);
    minl=min(minl, codeLength[i]);
  }
  printf("%d %d",minl,maxl);
  return 0;
}
