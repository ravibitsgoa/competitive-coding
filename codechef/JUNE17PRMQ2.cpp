#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

inline void fastRead_int(long long &x)
{ register int c = getchar_unlocked();
  x = 0;
  int neg = 0;
  for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
  if(c=='-')
  { neg = 1;
    c = getchar_unlocked();
  }
  for(; c>47 && c<58 ; c = getchar_unlocked())
  { x = (x<<1) + (x<<3) + c - 48;
  }
}

const int MAXN=1e5+2, MAXIND=4*MAXN;
vector<int> Segtree[MAXIND];   //Array and Segtree will follow  0-based and 1-based indexing respectively.
vector<int> Array[MAXN];
int primes[168]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
  223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
  521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853,
  857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

//initializes Segtree from Array.
void initialize(int node, int b, int e, int N)
{ if (b == e)
    Segtree[node] = Array[b];
  else
  { //compute the values in the left and right subtrees
    initialize(2*node,      b,            (b+e)/2,  N);
    initialize(2*node + 1,  (b+e)/2 + 1,  e,        N);
    Segtree[node].resize(Segtree[2*node].size() + Segtree[2*node +1].size());
    merge(Segtree[2*node].begin(), Segtree[2*node].end(), Segtree[2*node +1].begin(), Segtree[2*node +1].end(), Segtree[node].begin());
    sort(Segtree[node].begin(), Segtree[node].end());
  }
  //printf("%d ",node);
  //for(int i : Segtree[node])
    //printf("%d ",i);
  //printf("\n");
}

int query(int node, int b, int e, int i, int j, int X, int Y)
{
  int p1, p2;
  //if the current interval doesn't intersect
  //the query interval return -1
  if (i > e || j < b)
    return -1;

  //if the current interval is included in
  //the query interval return Segtree[node]
  if (b >= i && e <= j)
  { auto lowerlimit= lower_bound(Segtree[node].begin(), Segtree[node].end(), X);
    auto upperlimit= upper_bound(Segtree[node].begin(), Segtree[node].end(), Y);
    return upperlimit-lowerlimit;
  }

  p1 = query(2*node,      b,            (b+e)/2,  i, j, X, Y);
  p2 = query(2*node + 1,  (b+e)/2 + 1,  e,        i, j, X, Y);

  if (p1 == -1)
    return p2;
  if (p2 == -1)
    return p1;
  return p1 + p2;
}

int main()
{ long long N;
  fastRead_int(N);
  long long a[N];
  for(int i=0; i<N; i++)
    fastRead_int(a[i]);
  long long Q;
  fastRead_int(Q);

  for(int i=0; i<N; i++)
  { long long temp=a[i];
    for(int j=0; j<168 && temp>1; j++)
    { while(temp % primes[j] == 0)
      { Array[i].push_back(primes[j]);
        temp/=primes[j];
      }
    }
    if(temp>1)
    { Array[i].push_back(temp);
    }
  }

  initialize(1, 0, N-1, N);
  while(Q--) //For each query, we search for L to R on all of the 168 segment trees.
  { long long L, R, X, Y;
    fastRead_int(L);
    fastRead_int(R);
    fastRead_int(X);
    fastRead_int(Y);
    L--; R--;
    long long que=query(1, 0, N-1, L, R, X, Y);
    printf("%lld\n",que);
  }
return 0;
}
