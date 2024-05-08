// Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
// Input
// The only input line has two integers a and b.
// Output
// Print one integer: the minimum number of moves.
// Constraints

// 1 \le a,b \le 500

// Example
// Input:
// 3 5

// Output:
// 3

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function to find the minimum number of moves required to
// cut a rectangle of A X B into squares
ll solve(ll A, ll B)
{
    // dp[][] table such that dp[i][j] stores the minimum
    // number of cuts required to cut a rectangle of size (i
    // X j) into squares
    vector<vector<int> > dp(A + 1, vector<int>(B + 1, 1e9));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            // If the rectangle is already a square, then 0
            // cuts are required
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                // Iterate over all the possible cuts we can
                // make horizontally
                for (int k = 1; k < j; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[i][k] + dp[i][j - k] + 1);
                }
                // Iterate over all the possible cuts we can
                // make vertically
                for (int k = 1; k < i; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    // Return the minimum  number of cuts required to cut a
    // rectangle of size (A X B) into squares
    return dp[A][B];
}

int main()
{
    // Sample Input
    int A = 3, B = 5;
  
    cout << solve(A, B) << "\n";
}
