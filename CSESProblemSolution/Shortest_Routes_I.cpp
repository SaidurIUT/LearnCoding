#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX


typedef pair<int, int> iPair;


class Graph {
    int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<pair<int, int> >* adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    //adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair> >
        pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<long long> dist(V+1, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(1, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a
        // vertex
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current
            // adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    //printf("Vertex Distance from Source\n");
    for (int i = 1; i < V; ++i)
        printf("%d ", dist[i]);
}

int main()
{
    int V ,m;
    cin >> V >> m;
    Graph g(V+1);
    int a,b,c;
    for(int i=0; i< m ; i++){
        cin >> a >> b >> c ;
        g.addEdge(a,b,c);
    }

    // g.addEdge(0, 1, 4);
    // g.addEdge(0, 7, 8);
    // g.addEdge(1, 2, 8);
    // g.addEdge(1, 7, 11);
    // g.addEdge(2, 3, 7);
    // g.addEdge(2, 8, 2);
    // g.addEdge(2, 5, 4);
    // g.addEdge(3, 4, 9);
    // g.addEdge(3, 5, 14);
    // g.addEdge(4, 5, 10);
    // g.addEdge(5, 6, 2);
    // g.addEdge(6, 7, 1);
    // g.addEdge(6, 8, 6);
    // g.addEdge(7, 8, 7);

    g.shortestPath(1);

    return 0;
}