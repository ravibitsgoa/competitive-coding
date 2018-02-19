/*#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

const long long INFINITY = 1e17;

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
	long long sum, mx, len;
	void assignLeaf(T value) 
	{	sum = -INFINITY;
		mx = value;
		len = 1;	//whether it's a leaf node or not.
	}
	void merge(const SegmentTreeNode<T, V> &left, const SegmentTreeNode<T, V> &right) 
	{	this->len = 2;	//not a leaf node.
		this->mx = max(right.mx, left.mx);
		
		if(left.len==2 && right.len ==2)
		{	this->sum = max3(left.sum, right.sum, left.mx + right.mx);
		}
		else if(left.len==1 && right.len==2)
		{	this->sum = max(right.sum, left.mx + right.mx);
		}
		else if(right.len==1 && left.len==2)
		{	this->sum = max(right.mx+ left.mx, left.sum);	
		}
		else//if both child are leaf nodes.
		{	this->sum = left.mx + right.mx;
		}
	}
  
	V getValue()
	{	//assert(len==2);
		return this->sum;
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
  
	V getValue(int lo, int hi) 
	{	//for(int i=1; i<size; i++)
			//cout<<nodes[i].lval<<' '<<nodes[i].rval<<' '<<nodes[i].getValue()<<endl;
	
		SegmentTreeNode<T, V> result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
  
	void update(int index, T value) 
	{	update(1, 0, N-1, index, value);
	}
  
private:	
	void buildTree(const T arr[], int stIndex, int lo, int hi) 
	{
		if (lo == hi) 
		{
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
  
	SegmentTreeNode<T,V> getValue(int stIndex, int left, int right, int lo, int hi) 
	{
		if (left == lo && right == hi)
			return nodes[stIndex];
			
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
  
	void update(int stIndex, int lo, int hi, int index, T value) 
	{
		if (lo == hi) 
		{
			nodes[stIndex].assignLeaf(value);
			return;
		}
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
    
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long N;
	cin>>N;
	long long a[N];
	for(int i=0; i<N; i++)
		cin>>a[i];
	SegmentTree<long long, long long> s(a, N);
	int M;
	cin>>M;
	while(M--)
	{
		int x, y;
		char c;
		cin >> c >> x >> y;
		if(c=='Q')
			cout << s.getValue(x-1, y-1)<<'\n';
		else
			s.update(x-1, y);
	}
}*/