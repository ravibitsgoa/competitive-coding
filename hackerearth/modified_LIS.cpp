#include <iostream>
#include <algorithm>
#include <utility>
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

const int MAXVAL = 1e5 + 5;


template <class T, class V>
class SegmentTreeNode 
{  
public:
	long long xstart, xend, LISlen, LISnum;
	void assignLeaf(T value, int LISlen, int LISnum)
	{
		xstart = xend= value;
		this->LISlen= LISlen;
		this->LISnum = LISnum;
	}
  
	void merge(const SegmentTreeNode<T, V> &left, const SegmentTreeNode<T, V> &right) 
	{	this->xstart = left.xstart;
		this->xend = right.xend;
		this->LISlen = left.LISlen + right.LISlen;
		this->LISnum = min(left.LISnum, right.LISnum);
	}
  
	V getValue()
	{
		return this->maxSum;
	}
};

// T is the type of input array elements
// V is the type of required aggregate statistic
template<class T, class V>
class SegmentTree 
{
	SegmentTreeNode<T, V>* positive;
	SegmentTreeNode<T, V>* negative;
	
	int N;

public:
	SegmentTree() 
	{	this->N = MAXVAL;
		long long size = getSegmentTreeSize(N);
		positive = new SegmentTreeNode<T, V>[size];
		negative = new SegmentTreeNode<T, V>[size];
		buildTree(1, 0, N-1);
	}
  
	void print()
	{
		for(int i=1; i<size; i++)
			cout<<nodes[i].getValue()<<endl;
	}
	
	~SegmentTree() 
	{	delete[] nodes;
	}
  
	pair<V, V> pquery(int lo, int hi) 
	{	SegmentTreeNode<T, V> result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	pair<V, V> nquery(int lo, int hi) 
	{	SegmentTreeNode<T, V> result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
  
	void update(int index, int LISlen, int LISnum) 
	{	update(1, 0, N-1, index, LISlen, LISnum);
	}
  
private:	
	void buildTree(int stIndex, int lo, int hi) 
	{
		if (lo == hi) 
		{
			nodes[stIndex].assignLeaf(lo, 1, 1);
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
  
	void update(int stIndex, int lo, int hi, int index, int LISlen, int LISnum) 
	{
		if (lo == hi) 
		{
			nodes[stIndex].assignLeaf(value, LISlen, LISnum);
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
	SegmentTree<long long, long long> s;
	for(int i=0; i<N; i++)
	{	if(a[i]<0)
		{	pair<long long, long long> LIS = s.pquery(1, -a[i]-1);
			//LIS.first = length of LIS(es)
			//LIS.second = number of LIS(es).
			negative.pupdate(-a[i], LIS.first, LIS.second);
		}
		else
		{	pair<long long, long long> LIS = negative.nquery(1, a[i]-1);
			positive.nupdate(a[i], LIS.first, LIS.second);
		}
	}
	pair<long long, long long> rootLIS = s.pquery(1, MAXVAL);
	pair<long long, long long> rootLIS2 = s.nquery(1, MAXVAL);
	if(rootLis.first < rootLIS2.first)
		rootLIS = rootLIS2;
	cout<<rootLIS.first<<' '<<rootLIS.second;
}