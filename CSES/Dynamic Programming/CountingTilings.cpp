// Your task is to count the number of ways you can fill an n \times m grid using 1 \times 2 and 2 \times 1 tiles.
// Input
// The only input line has two integers n and m.
// Output
// Print one integer: the number of ways modulo 10^9+7.
// Constraints

// 1 \le n \le 10
// 1 \le m \le 1000

// Example
// Input:
// 4 7

// Output:
// 781

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// dp array to memoize results of subproblems
ll dp[1050][2050]; // dp[i][mask] stores the number of ways to fill the grid starting from column i with the mask representing the current state of filled cells

const int MOD = 1e9 + 7;

// Function to generate the next possible mask based on the current mask and position
void generateNextMask(int n, int curr_mask, int new_mask, int j, vector<int> &nextMask)
{
    if (j == n)
    {
        nextMask.push_back(new_mask);
        return;
    }
    // If there's enough space and cells are empty, place a 2x1 tile
    if (j + 1 < n && (((1 << j) & (curr_mask)) == 0) && (((1 << (j + 1)) & (curr_mask)) == 0))
    {
        generateNextMask(n, curr_mask, new_mask, j + 2, nextMask);
    }
    // Place a 1x2 tile if the cell is empty
    if ((((1 << j) & (curr_mask)) == 0))
    {
        generateNextMask(n, curr_mask, new_mask + (1 << j), j + 1, nextMask);
    }
    // Move to the next cell if the current cell is already filled
    if ((((1 << j) & (curr_mask)) != 0))
    {
        generateNextMask(n, curr_mask, new_mask, j + 1, nextMask);
    }
}

// Recursive function to compute the number of ways to fill the grid
ll countWays(int n, int m, int i, int mask)
{
    // Base case: reached the end of the grid
    if (i == m)
    {
        // If the entire grid is filled, return 1, otherwise return 0
        if (mask == 0)
            return 1;
        else
            return 0;
    }

    // If the result for the current state is already computed, return it
    if (dp[i][mask] != -1)
        return dp[i][mask];

    // Generate next possible masks for the current column
    vector<int> nextMask;
    generateNextMask(n, mask, 0, 0, nextMask);

    // Initialize the answer for the current state
    long long ans = 0;

    // Iterate over all possible next masks and recursively compute the answer
    for (auto x : nextMask)
    {
        ans = (ans % MOD + countWays(n, m, i + 1, x) % MOD) % MOD;
    }

    // Memoize the result and return it
    dp[i][mask] = ans;
    return dp[i][mask];
}

// Driver Code
int main()
{
    ll n=2, m=2;
    

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    // Compute and print the number of ways to fill the grid
    cout << countWays(n, m, 0, 0) << endl;
    return 0;
}

