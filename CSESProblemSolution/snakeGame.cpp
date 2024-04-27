#include <bits/stdc++.h>

using namespace std;

char grid[1009][1009];
// vector<vector<int>> vis(1009, vector<int>(1009, 0));
int vis[1009][1009]; // as it is created globally all of its element is set to zero
int n, m;

void dfs(int x, int y)
{
    //base cases;
    if(x < 0 || y < 0 || x > n || y > m) return;
    if(grid[x][y] == '!' || vis[x][y] == 1) return;

    vis[x][y] = 1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && vis[i][j] == 0)
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
}