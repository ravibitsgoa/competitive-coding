/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=200000, MAXIND=4*MAXN;
int Segtree[MAXIND], Array[MAXN]={0};   //Array and Segtree will follow  0-based and 1-based indexing respectively.
//Below is an implementation of segment tree for RMQ.
//Elements of the segment tree contain the index of the min element of the array.

//initializes elements of Segtree with -1.
//const int inf = -1;
void init(void)
{ for(int i=0; i<MAXIND; i++)
    Segtree[i]=-1;
}

//initializes Segtree from Array.
void initialize(int node, int b, int e, int N)
{ if (b == e)
    Segtree[node] = b;
  else
  { //compute the values in the left and right subtrees
    initialize(2*node,      b,            (b+e)/2,  N);
    initialize(2*node + 1,  (b+e)/2 + 1,  e,        N);
    //search for the minimum value in the first and
    //second half of the interval
    if (Array[Segtree[2*node]] <= Array[Segtree[2*node + 1]])
      Segtree[node] = Segtree[2*node];
    else
      Segtree[node] = Segtree[2*node + 1];
  }
}

//Returns the index of the smallest element in the given range [i, j].
int query(int node, int b, int e, int i, int j)
{
  int p1, p2;
  //if the current interval doesn't intersect
  //the query interval return -1
  if (i > e || j < b)
    return -1;

  //if the current interval is included in
  //the query interval return Segtree[node]
  if (i <= b && e <= j)
    return Segtree[node];

  //compute the minimum position in the
  //left and right part of the interval
  p1 = query(2*node,      b,            (b+e)/2,  i, j);
  p2 = query(2*node + 1,  (b+e)/2 + 1,  e,        i, j);

  //return the position where the overall
  //minimum is
  if (p1 == -1)
    return p2;
  if (p2 == -1)
    return p1;
  if (Array[p1] <= Array[p2])
    return p1;
  return p2;
}

int main()
{
	int n, k;
	cin>>n>>k;
	int xors[n]={0};
	for(int i=0; i<n; i++)
	{	cin>>Array[i];
		if(i==0)
			xors[i] = Array[i];
		else
			xors[i] = xors[i-1] ^ Array[i];
	}
	
	initialize(1, 0, n-1, n);
	//for(int i=0; i<2*n; i++)
	//	cout <<i<<' '<<Segtree[i] << ' '<<Array[Segtree[i]]<<endl;
	vector<long long> temp;
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			long long m=query(1, 0, n-1, i, j);
			m= Array[m];
			if(i>0)
				temp.push_back(m*(xors[j]^xors[i-1] ));
			else
				temp.push_back(m*(xors[j]));
			//cout << i+1<<' '<<j+1<<' '<<m<<' '<<temp[temp.size()-1]<<endl;
		}
		//for(int i=0; i<2*n; i++)
		//	cout <<i<<' '<<Segtree[i] << ' '<<Array[Segtree[i]]<<endl;
	
	}
	sort(temp.begin(), temp.end());
	//for(long long i : temp)
	//	cout << i<< endl;
	cout << temp[k-1];
}*/