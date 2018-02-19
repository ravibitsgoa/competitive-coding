#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
const long long INF = 1e16;
int main()
{	
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{	int n, q;
		cin>>n>>q;
		vector<long long> node[n+1];
		for(int i=1; i<=n; i++)
		{	int a;
			cin>>a;
			node[i].resize(a+1);	
			//node[i][j] = distance of jth node of ith cycle from 1st node of that cycle.
			node[i][0]=node[i][1]=0;
			for(int j=1; j<=a; j++)
			{	int d;
				cin>>d;
				node[i][(j%a)+1] = node[i][j]+d;
			}
		}
		//cycle_dist[i] denotes distance of ith cycle from 1st cycle.
		long long cycle_dist[n+1];
		int v1[n+1];
		int v2[n+1];
		int w[n+1];
		for(int i=1; i<=n; i++)
		{	int x1, x2;
			cin>>x1>>x2>>w[i];
			v2[i]=x1;	//outgoing vertex v2.
			v1[(i%n)+1]=x2;	//incoming vertex v1.
		}
		cycle_dist[0]=cycle_dist[1]=0;
		long long shortest_end[n+1];
		for(int i=1; i<=n; i++)
		{	int next = (i%n) +1;
			long long dv1v2 = abs(node[i][v2[i]] - node[i][v1[i]]);
			dv1v2= min( dv1v2, node[i][1] - dv1v2 );
			shortest_end[i] = dv1v2;
			cycle_dist[next] = cycle_dist[i] + w[i] + dv1v2;
		}
		
		//Now, queries:
		while(q--)
		{	int node1, c1, node2, c2;
			cin>>node1>>c1>>node2>>c2;
			assert(c1!=c2);
			long long d_n1_end = 
			min(abs(node[c1][v2[c1]] - node[c1][node1]), node[c1][1]- abs(node[c1][v2[c1]] - node[c1][node1]));
			long long d_n1_start = 
			min(abs(node[c1][v1[c1]] - node[c1][node1]), node[c1][1]- abs(node[c1][v1[c1]] - node[c1][node1]));
			long long d_n2_end = 
			min(abs(node[c2][v2[c2]] - node[c2][node2]), node[c2][1]- abs(node[c2][v2[c2]] - node[c2][node2]));
			long long d_n2_start = 
			min(abs(node[c2][v1[c2]] - node[c2][node2]), node[c2][1]- abs(node[c2][v1[c2]] - node[c2][node2]));
			long long cycle = cycle_dist[c2]-cycle_dist[c1];
			long long dmin;
			if(cycle>=0)
			{	//cout<<'a'<<' '<<d_n1_start<<' '<<d_n1_end<<' '<<d_n2_start<<' '<<d_n2_end<<' '<<cycle<<' '<<cycle_dist[1]<<endl;
				//Bro, this is a debugging statement. ismein kuchh nahin milega.
				dmin = min(d_n1_end+ d_n2_start + cycle -shortest_end[c1], 
				cycle_dist[1]-cycle + d_n1_start + d_n2_end -shortest_end[c2]);
			}
			else
			{	//cout<<'b'<<' '<<d_n1_start<<' '<<d_n1_end<<' '<<d_n2_start<<' '<<d_n2_end<<' '<<cycle<<' '<<cycle_dist[1]<<endl;
				dmin = min(d_n2_end -cycle + d_n1_start -shortest_end[c2],
				cycle_dist[1]+cycle + d_n1_end+ d_n2_start -shortest_end[c1]);
			}
			cout<<dmin<<'\n';
		}
	}
	
}