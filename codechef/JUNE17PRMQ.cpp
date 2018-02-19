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
struct node
{ long long sum;
  int l, r;
};
long long avg(long long x, long long y)
{ long long sum=x+y;
  if(sum%2)
    sum++;
  return sum/2;
}
long long getSum(struct node* segtree, int L, int R, int j)
{ if(segtree[(j-1)/2].r - segtree[(j-1)/2].l ==1)
    return 0;
  if(L <= segtree[j].l && segtree[j].r <= R)
    return segtree[j].sum;
  else if(segtree[j].r<L || segtree[j].l>R)
    return 0;
  else
    return getSum(segtree, L, R, 2*j+1) + getSum(segtree, L, R, 2*j+2);
}
int main()
{
  long long N;
  fastRead_int(N);
  long long a[N];
  for(int i=0; i<N; i++)
    fastRead_int(a[i]);
  long long Q;
  fastRead_int(Q);
  int primes[168]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
    223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
    521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853,
    857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
  vector<int>pr(primes, primes+168);
  int ans[N][169]={0}, bigprime[N]={0};
  struct node segtree_sums[169][2*N];
  for(int i=0; i<N; i++)
  { long long temp=a[i];
    for(int j=0; j<168; j++)
    { long ghaat=0;
      while(temp % primes[j] ==0)
      { ghaat++;
        temp/=primes[j];
      }
      ans[i][j]=ghaat;
    }
    if(temp>1)
    { bigprime[i]=temp;
    }
  }
  for(int k=0; k<168; k++)
  { segtree_sums[k][0].l=0;
    segtree_sums[k][0].r=N-1;
    for(int j=1; j<2*N; j++)
    { if((j-1)%2 == 0)
      { segtree_sums[k][j].l = segtree_sums[k][(j-1)/2].l;
        segtree_sums[k][j].r = avg(segtree_sums[k][(j-1)/2].l, segtree_sums[k][(j-1)/2].r)-1;
      }
      else
      { segtree_sums[k][j].r = segtree_sums[k][(j-1)/2].r;
        segtree_sums[k][j].l = avg(segtree_sums[k][(j-1)/2].l, segtree_sums[k][(j-1)/2].r);
      }
    }   //This upper part stores limits of sums in each node.
    //The lower part stores sums into the appropriate nodes of the segment tree.
    for(int i=0; i<N; i++)
    { for(int j=0; j<2*N-1;)
      { segtree_sums[k][j].sum+=ans[i][k];
        j=2*j+1;
        if(i>segtree_sums[k][j].r)
          j++;
      }
    }
  }
  while(Q--) //For each query, we search for L to R on all of the 168 segment trees.
  { long long L, R, X, Y;
    fastRead_int(L);
    fastRead_int(R);
    fastRead_int(X);
    fastRead_int(Y);
    L--; R--;
    long long query=0;
    auto lowerlimit= lower_bound(pr.begin(), pr.end(), X);
    auto upperlimit= lower_bound(pr.begin(), pr.end(), Y);
    while(primes[upperlimit-pr.begin()]>Y)
      upperlimit--;
    if(Y<=997)
    { for(int i=lowerlimit-pr.begin(); i<=upperlimit-pr.begin(); i++)
      { query+=getSum(segtree_sums[i], L, R, 0);
      }
    }
    else if(X<=997)
    { for(int i=lowerlimit-pr.begin(); i<=168; i++)
      { query+=getSum(segtree_sums[i], L, R, 0);
      }
      for(int j=L; j<=R; j++)
        if(bigprime[j] && bigprime[j]>=X && bigprime[j]<=Y)
          query++;
    }
    else
    { for(int j=L; j<=R; j++)
        if(bigprime[j] && bigprime[j]>=X && bigprime[j]<=Y)
          query++;
    }
    printf("%lld\n",query);
  }
return 0;
}
