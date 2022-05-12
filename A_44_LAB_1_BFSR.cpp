                        /*LAB 2*/
                /*BFS USING ADJAJENCY LIST*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct Edge {
    int src, dest;
};
 
class Graph
{
public:
    vector<vector <int> > adjList;
 
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
 
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
void BFS(Graph const &graph, queue<int> &q, vector<bool> &visited)
{
    
    
    if (q.empty()) {
        return;
    }
    int v = q.front();
    q.pop();
    cout << v << " ";
    for (int u: graph.adjList[v])
    {
        if (!visited[u])
        {
            visited[u] = true;
            q.push(u);
        }
    }
    BFS(graph, q, visited);
}
 
int main()
{
    vector<Edge> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
    int n = 6;
    Graph graph(edges, n);
    vector<bool> visited(n, false);
    queue<int> q;
    cout<<"BFS Traversal: "<<endl;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            q.push(i);
            BFS(graph, q, visited);
        }
    }
 
    return 0;
}
