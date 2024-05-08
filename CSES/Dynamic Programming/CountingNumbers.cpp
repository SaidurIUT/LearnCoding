#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp array to memoize results of subproblems
ll dp[20][10][2][2];

// Function to calculate the count of valid numbers using Digit DP
ll mem(string s, ll curr, ll prev_digit, ll leading_zero, ll tight)
{
    // Base case: entire number processed
    if (curr == 0)
    {
        return 1;
    }

    // Check if result for the current state is already computed
    if (dp[curr][prev_digit][leading_zero][tight] != -1)
        return dp[curr][prev_digit][leading_zero][tight];

    // Determine the limit for the current position based on tightness
    ll limit;
    if (tight == 0)
    {
        limit = 9;
    }
    else
    {
        ll sz = s.size();
        limit = s[sz - curr] - 48;
    }

    ll countNumbers = 0;

    // Iterate through possible digits for the current position
    for (ll curr_digit = 0; curr_digit <= limit; curr_digit++)
    {
        // Check validity based on constraints
        if (leading_zero == 0 && (curr_digit == prev_digit))
        {
            continue;
        }

        // Update state parameters based on the current digit
        ll new_leading_zero = (leading_zero == 1 && curr_digit == 0) ? 1 : 0;
        ll new_tight = (curr_digit == limit && tight == 1) ? 1 : 0;

        // Recursively call the mem function for the next position
        countNumbers += mem(s, curr - 1, curr_digit, new_leading_zero, new_tight);
    }

    // Update the memoization table with the count of valid numbers for the current state
    dp[curr][prev_digit][leading_zero][tight] = countNumbers;
  
    return dp[curr][prev_digit][leading_zero][tight];
}

// Driver Code
int main()
{
    ll a=123, b=321;
    
    ll count1 = 0;
    // Initialize dp table with -1
    memset(dp, -1, sizeof(dp));

    // Calculate count of valid numbers from [0, a-1]
    string str1 = to_string(a - 1);
    if (a != 0)
        count1 = mem(str1, str1.size(), -1, 1, 1);

    // Calculate count of valid numbers from [0, b]
    memset(dp, -1, sizeof(dp));
    string str2 = to_string(b);
    ll count2 = mem(str2, str2.size(), -1, 1, 1);

    // Output the difference between count of valid numbers from [0, b] and [0, a-1]
    cout << count2 - count1;
}



// Your task is to count the number of integers between a and b where no two adjacent digits are the same.
// Input
// The only input line has two integers a and b.
// Output
// Print one integer: the answer to the problem.
// Constraints

// 0 \le a \le b \le 10^{18}

// Example
// Input:
// 123 321

// Output:
// 171