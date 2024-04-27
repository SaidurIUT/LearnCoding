#include<bits/stdc++.h>
using namespace std;

int NO_PARENT = -1;

void printPath(int currentVertex, vector<int> parents){
    if(currentVertex == NO_PARENT){
        return;
    }

    printPath(parents[currentVertex],parents);
    cout<<currentVertex<<" ";
}

void printSolution(int startVertex, vector<int>distances , vector<int> parents){
    int nVertices = distances.size();
    cout << "Vertex \t Distance \t path "<<endl;
    for(int vertxIndex=0; vertxIndex < nVertices; vertxIndex++){
        if(vertxIndex != startVertex){
            cout<<endl<<startVertex<<" -> ";
            cout<<vertxIndex << "\t\t";
            cout<<distances[vertxIndex]<<"\t\t";
            printPath(vertxIndex,parents);
        }
    } 
}

void dijkstra (vector<vector <int> > adjacencyMatrix, int startVertex){
    int nVertices = adjacencyMatrix[0].size();
    vector<int> shortestDistances(nVertices,INT_MAX);
    vector<int> added(nVertices,false);

    shortestDistances[startVertex] = 0;
    vector<int> parents(nVertices);
    parents[startVertex] = NO_PARENT;

        for (int i = 1; i < nVertices; i++) {
 
        // Pick the minimum distance vertex
        // from the set of vertices not yet
        // processed. nearestVertex is
        // always equal to startNode in
        // first iteration.
        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            if (!added[vertexIndex]
                && shortestDistances[vertexIndex]
                       < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance
                    = shortestDistances[vertexIndex];
            }
        }
 
        // Mark the picked vertex as
        // processed
        added[nearestVertex] = true;
 
        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            int edgeDistance
                = adjacencyMatrix[nearestVertex]
                                 [vertexIndex];
 
            if (edgeDistance > 0
                && ((shortestDistance + edgeDistance)
                    < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex]
                    = shortestDistance + edgeDistance;
            }
        }
    }
 
    printSolution(startVertex, shortestDistances, parents);

}

int main()
{
    vector<vector<int> > adjacencyMatrix
        = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 0, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 14, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(adjacencyMatrix, 3);
    return 0;
}