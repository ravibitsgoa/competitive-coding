/*
Part 3/week 2/programming_assignment/problem2_of_clustring.
This program is used to find the number of clusters so that spacing is 3.
This implements a simple Union-Find data structure (without lazy unions or path compression.)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

static inline int distance(long long x, long long y)
{
    return __builtin_popcount(x^y);
}

int main()
{ int n;
  cin>>n;
  int len;
  cin>>len;
  long long graph[n]={0};
  int leader[n]={0};
  int size_of_my_cluster[n]={0};
  vector<int> nodes_of_cluster[n];
  for(int i=0; i<n; i++) //Initially each node is in its own cluster.
  { leader[i]=i;
    size_of_my_cluster[i]=1; //This size is defined only for the leader.
    nodes_of_cluster[i].push_back(i); //ith cluster contains only ith node.
  }
  for(int i=0; i<n; i++)
  { bool x;
    long long mul=1;
    for(int j=0; j<len; j++, mul<<=1)
    { cin>>x;
      graph[i]+=x*(mul);
    }
  }
  int num_clusters=n;
  for(int i=0; num_clusters>1 && i<n; i++)
  { for(int j=i+1; num_clusters>1 && j<n; j++)
    { if(leader[i]!=leader[j] && distance(graph[i], graph[j]) < 3)
      { num_clusters--;
        int smaller_one, bigger_one;
        if(size_of_my_cluster[i] <= size_of_my_cluster[j])
        { smaller_one = leader[i]; bigger_one = leader[j];
        }
        else
        { bigger_one = leader[i]; smaller_one = leader[j];
        }
        int newsize = size_of_my_cluster[j] + size_of_my_cluster[i];
        for(int k=nodes_of_cluster[smaller_one].size() -1; k>=0; k--)
        { leader[nodes_of_cluster[smaller_one][k]]=bigger_one;          //Updates leader pointer of each node of the smaller cluster.
          size_of_my_cluster[nodes_of_cluster[smaller_one][k]]=newsize; //Updates the size value of each node of the smaller cluster.
        }
        nodes_of_cluster[bigger_one].reserve(newsize);
        nodes_of_cluster[bigger_one].insert(nodes_of_cluster[bigger_one].end(), nodes_of_cluster[smaller_one].begin(), nodes_of_cluster[smaller_one].end());
        nodes_of_cluster[smaller_one].clear();  //Empties the smaller cluster.
      }
    }
  }
  cout<<num_clusters<<endl;
return 0;
}
