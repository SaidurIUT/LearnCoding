#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

typedef pair<int,int> ipair;

class Graph{
    int V;
    list<pair<int,int> > *adj;

public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    void shortestPath(int s);
};

Graph::Graph(int V){
    this->V =V;
    adj = new list<ipair>[V];
}

void Graph :: addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}


void Graph :: shortestPath(int src){
   priority_queue<ipair,vector<ipair>, greater<ipair> >pq;
   vector<int> dist (V,INF);

    pq.push(make_pair(0,src));
    dist[src]=0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        list<pair<int,int> > :: iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++){
            int v = (*i).first;
            int weight = (*i).second;
            if(dist[v]> dist[u]+weight){
                dist[v] = dist[u]+weight;

                pq.push(make_pair(dist[v],v));
            }
        }
    }

    printf("Varetex \t\t Distance from Source\n");
    for(int i=0; i<V ; i++){
        printf("%d \t\t %d\n",i,dist[i]);
    }
}

int main()
{
    // create the graph given in above figure
    int V = 9;
    Graph g(V);
 
    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    // Function call
    g.shortestPath(0);
 
    return 0;
}