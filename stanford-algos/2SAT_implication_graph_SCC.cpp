//Source: https://en.wikipedia.org/wiki/Implication_graph
//If the constraints are modelled as an implication graph, and none of them have
//their negation in the same SCC, then, we can claim that all constraints are satisfiable.
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
    int numSCC=0;
    vector<int> SCCindex;
    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, vector<bool> &visited);
public:
    Graph(int V);
    void addEdge(int v, int w);

    // The main function that finds and prints strongly connected components
    void isSatisfiable();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
    SCCindex.resize(V);
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, vector<bool> &visited)
{
    // Mark the current node as visited and print it
    visited.at(v) = true;
    SCCindex.at(v) = numSCC;
    //cout<<v<<' '<<SCCindex.at(v)<<endl;
    //cout << v << " ";
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
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

void Graph::addEdge(int v, int w)
{
    adj.at(v).push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, vector<bool> &visited, stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited.at(v) = true;
    //cout<<v<<endl;
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
void Graph::isSatisfiable()
{
    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    vector<bool> visited(V);
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
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {   int num=0;
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited.at(v) == false)
        {   gr.numSCC++;     //Increment the number of SCCs of a graph, on finding a new one.
            //cout<<v<<' '<<numSCC<<' ';
            gr.DFSUtil(v, visited); //Start DFS from vth node.
        }
    }

    int satisfiable=1;
    for(int i=0; i<V; i++)
    {   if((i!= V-i-1) && gr.SCCindex.at(i) == gr.SCCindex.at(V-i-1)) //If literal i and -i belong to same SCC, it's unsatisfiable.
        {   satisfiable=0;
            //cout<<i<<' '<<gr.SCCindex.at(i)<<endl;
        }
    }
    cout<<gr.numSCC;
    if(satisfiable==1)
        cout<<"yes";
    else
        cout<<"no";
}

// Driver program to test above functions
int main()
{
    int n;
    scanf("%d",&n);
    // Create a graph given in the above diagram
    int V=2*n + 1;
    Graph g(V);

    vector<int> vars(n+1);
    pair<int, int> inp[n];  //Set of all constraints
    for(int i=0; i<n; i++)
        vars[i]=-1;

    for(int i=0; i<n; i++)
    {   scanf("%d %d", &inp[i].first, &inp[i].second);
        g.addEdge(-inp[i].first + n, inp[i].second + n);//Added n to all to make them positive.
        //cout<<-inp[i].first + n<<' '<<inp[i].second + n<<endl;
        g.addEdge(-inp[i].second + n, inp[i].first + n);
        //cout<<-inp[i].second + n<<' '<<inp[i].first + n<<endl;
    }
    //cout << "Following are strongly connected components in "<<"given graph \n";
    g.isSatisfiable();
    return 0;
}
