// *Types of graph*
// 1. directed graph
// 2. Undirected graph


#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph{
    
public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u , int v, bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v

        adj[u].push_back(u);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<" --> " ;
            for(auto j: i.second){
                cout << j << " ";
            }

            cout<<endl;
        }
    }


};


int main(){
    
    int n ; 
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0 ; i<m ; i++){
        int v,u;
        cin>>u >> v;

        //creating a undirected graph

        g.addEdge(u,v,0);

    }

    g.printAdjList();
}