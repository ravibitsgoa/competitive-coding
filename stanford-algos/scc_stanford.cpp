//Computes strongly connected components of a directed graph in O(m+n) time using
//Kosaraju's algorithm.
//source: Geeksforgeeks.com
#include <iostream>     //for cin, cout
#include <list>
#include <stack>
#include <vector>
#include <algorithm>    //for std::sort
#include <functional>   //for std::greater
using namespace std;

class Graph
{
private:
    int V;    // No. of vertices
    vector<list<int> > adj;    // An array of adjacency lists

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[], int &num);
public:
    Graph(int V);
    void addEdge(int &v, int &w);

    // The main function that finds and prints strongly connected components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[], int &num)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    //cout << v << " ";
    num++;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, num);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int &v, int &w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool visited [V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
    vector<int>sizes;
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {   int num=0;
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited, num);
            //cout <<num<< endl;
            sizes.push_back(num);
        }
    }

    sort(sizes.begin(), sizes.end(), greater<int>());
    for(int i=0; i<5; i++)  //Prints the sizes of biggest 5 SCCs of the graphs.
        cout<<sizes[i]<<endl;
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    int V=875715;
    Graph g(V);
    int x, y;
    while(cin>>x && cin>>y)
    { g.addEdge(x,y);
      //Graph::adj[x].push_back(y);
    }
    //cout << "Following are strongly connected components in "<<"given graph \n";
    g.printSCCs();

    return 0;
}
