/*#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
T max3(const T& a, const T& b, const T& c)
{
	return max(max(a, b), c);
}
template <class T>
T max4(const T&a, const T&b, const T&c, const T&d)
{
	return max(max(max(a, b), c), d);
}

template <class T, class V>
class SegmentTreeNode 
{  
public:
	long long sum, lazy;
	int leaf, l, r, len;
	
	SegmentTreeNode()
	{	sum= lazy= 0;
		leaf= 0;
	}
	
	void assignLeaf(T value, int l) 
	{	leaf=1;
		len = 1;
		sum = value;
		this->l = this->r = l;
	}
  
	void merge(SegmentTreeNode<T, V> &left, SegmentTreeNode<T, V> &right) 
	{	leaf = 0;
		this->l = left.l;
		this->r = right.r;
		this->len = this->r - this->l +1;
	
		this->sum = lazy*len + left.getValue() + right.getValue();
		this->lazy = 0;
	}
	
	V getValue()
	{	
		return sum+ (lazy * len);
	}
};

// T is the type of input array elements
// V is the type of required aggregate statistic
template<class T, class V>
class SegmentTree 
{
	SegmentTreeNode<T, V>* nodes;
	int N;
	long long size;
public:
	SegmentTree(const T arr[], int N) 
	{	this->N = N;
		size = getSegmentTreeSize(N);
		nodes = new SegmentTreeNode<T,V>[size];
		buildTree(arr, 1, 0, N-1);
	}
  
	~SegmentTree() 
	{	delete[] nodes;
	}
	
	void print()
	{	for(int i=1; i<size; i++)
			cout<<nodes[i].sum<<' '<<nodes[i].lazy<<' '<<nodes[i].l<<' '<<nodes[i].r<<endl;
	}
	
	V getValue(int lo, int hi) 
	{	SegmentTreeNode<T, V> result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
  
	void update(int l, int r, T val)
	{
		update(1, 0, N-1, l, r, val);
	}
private:	
	void buildTree(const T arr[], int stIndex, int lo, int hi) 
	{
		if (lo == hi) 
		{
			nodes[stIndex].assignLeaf(arr[lo], lo);
			return;
		}
    
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
  
	SegmentTreeNode<T,V> getValue(int stIndex, int left, int right, int lo, int hi) 
	{
		if (left == lo && right == hi)	//If we already are in the correct node, we return it.
			return nodes[stIndex];
		
		//If it's a non-leaf node, we propagate it's lazy sum.
		nodes[2*stIndex].lazy += (nodes[stIndex].lazy*nodes[2*stIndex].len +0.0)/nodes[stIndex].len;
		nodes[2*stIndex +1].lazy += (nodes[stIndex].lazy*nodes[2*stIndex +1].len +0.0)/nodes[stIndex].len;
		nodes[stIndex].lazy = 0;
		
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode<T,V> leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode<T,V> rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode<T,V> result;
		result.merge(leftResult, rightResult);
		return result;
	}
  
	int getSegmentTreeSize(int N) 
	{
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
  
	void update(int stIndex, int lo, int hi, int l, int r, T value) 
	{
		assert(nodes[stIndex].l ==lo && nodes[stIndex].r ==hi);
		if (nodes[stIndex].r <l || nodes[stIndex].l > r)	//node out of range [l, r].
			return;
			
		if (nodes[stIndex].l >=l && nodes[stIndex].r <= r)	//if it falls completely in the range or its a leaf.
		{	nodes[stIndex].lazy += value;
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		nodes[left].lazy  += nodes[stIndex].lazy;
		nodes[right].lazy += nodes[stIndex].lazy;
		nodes[stIndex].lazy = 0;
		if (l <= mid)
			update(left, lo, mid, l, r, value);
		if (r > mid)
			update(right, mid+1, hi, l, r, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{	long long N, M;
		cin>>N>>M;
		long long a[N];
		for(int i=0; i<N; i++)
			a[i]=0;
		SegmentTree<long long, long long> s(a, N);
		while(M--)
		{
			int c, x, y;
			cin>>c>>x>>y;
			if(c==1)
				cout<<s.getValue(x-1, y-1)<<'\n';
			else
			{	long long v;
				cin>>v;
				s.update(x-1, y-1, v);
				s.print();
			}
		}
	}
}*/