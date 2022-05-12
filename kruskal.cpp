#include <algorithm>
#include <iostream>
using namespace std;

class Edge
{
    public:
        int source, destination, weight;
};

bool compare(Edge e1, Edge e2)
{
    return (e1.weight < e2.weight);
}

int findParent(int v, int *parent)
{
    if(parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *obj, int edges, int vertices)
{
    sort(obj, obj + edges, compare);
    Edge *output = new Edge[edges-1];
    int *parent = new int[vertices];

    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }
    
    int count = 0;
    int i = 0;
    while(count != vertices-1)
    {
        Edge currentEdge = obj[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.destination, parent);

        if(sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    for (int i = 0; i < vertices-1; i++)
    {
        if(output[i].source < output[i].destination)
        {
            cout<<output[i].weight<<" "<<output[i].source<<" "<<output[i].destination<<endl;
        }
        else
        {
            cout<<output[i].weight<<" "<<output[i].destination<<" "<<output[i].source<<endl;
        }
    }
}

int main()
{
    int vNumber, eNumber;

    cout<<"Enter number of (vertices, edges): ";
    cin>>vNumber>>eNumber;
 
    Edge *obj = new Edge[eNumber];

    int w, s, d;
    cout<<"Enter (weight, source, destination): "<<endl;
    for (int i = 0; i < eNumber; i++)
    {
        cin>>w>>s>>d;
        obj[i].weight = w;
        obj[i].source = s;
        obj[i].destination = d;
    }
    
    cout<<"MST for given graph (weight, source, destination): "<<endl;
    
    kruskals(obj, eNumber, vNumber);
    
    return 0;
}