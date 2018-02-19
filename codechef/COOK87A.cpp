#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=300005;
const int MAX= 4*N; // Why? :D
const long long inf= 1e17;

int arr[N];
int tree[MAX];
int left[MAX], right[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b, int m) {
    if(a > b) return; // Out of range
  	
  	if(a == b) 
	{ 	// Leaf node
    	tree[node] = arr[a]; // Init value
		if(arr[a]>=m)
			left[node]= right[node] = a;
		else
		{	left[node]=0; right[node] = -1;
		}
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = tree[node*2] ^ tree[node*2+1]; // Init this value
	if(tree[node*2] >= m)
	{	right[node]=right[node*2];
		left[node] = left[node*2];
	}
	if(tree[node*2 +1] >= m)
	{	if((tree[node*2]>=m && (right[node*2 +1]-left[node*2 +1] < right[node*2]-left[node*2])) || (tree[node*2]<m))
		{	right[node] = right[node*2 +1];
			left[node]  = left[node*2 +1];
		}
	}
	if(tree[node] >= m && tree[node*2]<m && tree[node*2 +1]<m)
	{	
		
	}
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
    
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b) { // Leaf node
    		tree[node] += value;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{	
	}
	return 0;
}