#include<bits/stdc++.h>
using namespace std;

#define n 4

#define INF 99999

void printSolution(int dist[n][n]);

void floydWarshall(int dist[n][n]) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[i][k] != INF && dist[k][j] != INF)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}

void printSolution(int dist[n][n]) {
    cout << "The following matrix shows the shortest "
         << "distances"
         << " between every pair of vertices \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int graph[n][n] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    floydWarshall(graph);
    return 0;
}