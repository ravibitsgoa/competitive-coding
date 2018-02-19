//This implements segment tree. source: topcoder tutorials.
//https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Segment_Trees
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=600000, MAXIND=4*MAXN;
int Segtree[MAXIND], Array[MAXN]={0};   //Array and Segtree will follow  0-based and 1-based indexing respectively.
//Below is an implementation of segment tree for RMQ.
//Elements of the segment tree contain the index of the min element of the array.

//initializes elements of Segtree with -1.
void init(void)
{   for(int i=0; i<MAXIND; i++)
        Segtree[i]=-1;
}

//initializes Segtree from Array.
void initialize(int node, int b, int e, int N)
{   if (b == e)
        Segtree[node] = b;
    else
    {   //compute the values in the left and right subtrees
        initialize(2*node,      b,            (b+e)/2,  N);
        initialize(2*node + 1,  (b+e)/2 + 1,  e,        N);
        //search for the minimum value in the first and
        //second half of the interval
        Segtree[node] = Segtree[2*node + 1]^Segtree[2*node];
    }
}

//Returns the index of the smallest element in the given range [b, e].
int query(int node, int b, int e, int i, int j)
{   cout<<node<<' '<<b<<' '<<e<<' '<<i<<' '<<j<<'\n';
    int p1, p2;
    //if the current interval doesn't intersect
    //the query interval return -1
    if (i > e || j < b)
        return 0;

    //if the current interval is included in
    //the query interval return Segtree[node]
    if (b >= i && e <= j)
        return Segtree[node];

    //compute the minimum position in the
    //left and right part of the interval
    p1 = query(2*node,      b,            (b+e)/2,  i, j);
    p2 = query(2*node + 1,  (b+e)/2 + 1,  e,        i, j);

    //return the position where the overall
    //minimum is
    cout<<(p1^p2)<<'\n';
    return p1^p2;
}



int main(void)
{   init();
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {   cin>>Array[i];
    }
    initialize(1, 0, N-1, N);
    int Q;
    cin>>Q;
    while(Q--)
    {   int l, r;
        cin>>l>>r;
        cout<<query(1, 0, N-1, l-1, r-1)<<'\n';
    }
    return 0;
}
