#include<bits/stdc++.h>

using namespace std;

void floyd_warshall(vector<vector<int>>& matrix) 
{
    int n = matrix.size();

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int i = 0;
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        floyd_warshall(matrix);

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int q;
        cin >> q;

        int sum = 0;
        for(int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            sum += matrix[u-1][v-1];
        }

        printf("Case #%d: %d\n", ++i, sum);
    }
}