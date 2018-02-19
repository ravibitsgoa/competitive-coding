/*
Part 3/week 2/programming_assignment/problem1_of_clustring.
This computes the spacing for k-clustering, where k is set as 4. (The input graph will be partitioned into 4 clusters.)
This implements a simple Union-Find data structure (without lazy unions or path compression.)
A runtime of O(N^2 * logN + N^2 + N^2 * logN) is garunteed.
(sorting of edges + N^2 *1 for cycle-checks + N^2*logN for leader pointer updates.)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{ int N1, N2, cost;
};
bool edgeCompare(edge i, edge j)
{ return (i.cost <= j.cost);
}
int main()
{ int n;
  cin>>n;
  const int NUM_EDGES=(n*(n-1))/2;
  edge graph[NUM_EDGES];
  int leader[n+1]={0};                        //0th node doesn't exist.
  int size_of_my_cluster[n+1]={0};
  vector<int> nodes_of_cluster[n+1];
  for(int i=1; i<=n; i++)                     //Initially each node is in its own cluster.
  { leader[i]=i;
    size_of_my_cluster[i]=1;                  //This size is defined only for the leader.
    nodes_of_cluster[i].push_back(i);         //ith cluster contains only ith node.
  }
  for(int i=0; i<NUM_EDGES; i++)
    cin >> graph[i].N1 >> graph[i].N2 >> graph[i].cost;
  const int k=4;                              //This is the final number of clusters that we want.

  sort(graph, graph + NUM_EDGES, edgeCompare);

  int num_clusters=n;
  for(int i=0; num_clusters>k && i<NUM_EDGES; i++)
  { if(leader[graph[i].N1]!=leader[graph[i].N2])
    { num_clusters--;
      int smaller_one, bigger_one;
      if(size_of_my_cluster[graph[i].N1] <= size_of_my_cluster[graph[i].N2])
      { smaller_one = leader[graph[i].N1]; bigger_one = leader[graph[i].N2];
      }
      else
      { bigger_one = leader[graph[i].N1]; smaller_one = leader[graph[i].N2];
      }
      int newsize = size_of_my_cluster[graph[i].N2] + size_of_my_cluster[graph[i].N1];
      for(int j=nodes_of_cluster[smaller_one].size() -1; j>=0; j--)
      { leader[nodes_of_cluster[smaller_one][j]]=bigger_one;          //Updates leader pointer of each node of the smaller cluster.
        size_of_my_cluster[nodes_of_cluster[smaller_one][j]]=newsize; //Updates the size value of each node of the smaller cluster.
      }
      nodes_of_cluster[bigger_one].reserve(newsize);
      nodes_of_cluster[bigger_one].insert(nodes_of_cluster[bigger_one].end(), nodes_of_cluster[smaller_one].begin(), nodes_of_cluster[smaller_one].end());
      nodes_of_cluster[smaller_one].clear();  //Empties the smaller cluster.
    }
  }
  for(int i=0; i<NUM_EDGES; i++)
  { if(leader[graph[i].N1] != leader[graph[i].N2])  //This prints the minimum distance among the separated pairs of points.
    { cout<<graph[i].cost<<endl;                    //I.e. the spacing of the clustering.
      break;
    }
  }
return 0;
}
