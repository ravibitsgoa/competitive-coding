#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

void modify(int l, int r, int value) 
{
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
  { if (l&1)  t[l++] +=value;
    if (r&1) t[--r] +=value;
  }
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin>>n>>Q;
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    build();
    //modify(0, 1);
    //printf("%d\n", query(3, 11));
    while(Q--)
    { int Type, L, R;
      cin>>Type>>L>>R;
      if(Type==2)
      { int x;
        cin>>x;
        modify(L, R, x);
        push();
      }
      else
      { cout<<query(L, R)<<'\n';
      }
    }
    return 0;
}
s
