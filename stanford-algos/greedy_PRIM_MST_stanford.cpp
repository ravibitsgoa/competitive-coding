#include <iostream>
const int INF=10000;

using namespace std;
int main()
{ 	int Nodes, edges;
	cin>>Nodes>>edges;
	int edge_costs[edges], n1[edges], n2[edges];
	for(int i=0; i<edges; i++)
		cin>>n1[i]>>n2[i]>>edge_costs[i];
	bool visited[Nodes+1]={0};
	int root=1;
	visited[root]=1;
	int numVisitedNode=1;
	long long sumOfMST=0;
	while(numVisitedNode != Nodes)
	{ 	int costOfEdge=INF, edgeNumber=-1;
		for(int i=0; i<edges; i++)
		{ 	if(edge_costs[i]<costOfEdge && (visited[n1[i]] ^ visited[n2[i]]))
			{ 	costOfEdge = edge_costs[i];
				edgeNumber = i;
			}
		}
		sumOfMST += costOfEdge;
		visited[n1[edgeNumber]] = visited[n2[edgeNumber]]=1;
		numVisitedNode++;
	}
	cout<<sumOfMST;
return 0;
}
