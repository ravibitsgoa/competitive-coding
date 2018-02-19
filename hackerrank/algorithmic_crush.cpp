#include<iostream>
using namespace std;
int main()
{ int N, Q;//Q number of Queries.
  cin>>N>>Q;
  //We shall make a segment tree storing max values.
  int ncopy=N;
  int size=0;
  while(N)
  { size+=N;
    N/=2;
  }
  int max_segment_tree[size]={0};
  
  while(Q--)
  { int l, r, inc;//increment inc from l to r inclusive.
    cin>>l>>r>>inc;

  }
return 0;
}
