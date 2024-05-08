// There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.
// What is the maximum possible score for the first player when both players play optimally?
// Input
// The first input line contains an integer n: the size of the list.
// The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
// Output
// Print the maximum possible score for the first player.
// Constraints

// 1 \le n \le 5000
// -10^9 \le x_i \le 10^9

// Example
// Input:
// 4
// 4 5 1 3

// Output:
// 8

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5000;

int N, x[maxN+1];
ll p[maxN+1], dp[maxN+1][maxN+1];
bool found[maxN+1][maxN+1];

ll sum(int l, int r){
	return p[r] - p[l-1];
}

ll solve(int l, int r){
	if(found[l][r])	return dp[l][r];
	if(l == r)		return x[l];
	found[l][r]=true;
	return dp[l][r] = max(x[l]+sum(l+1, r)-solve(l+1, r), x[r]+sum(l,r-1)-solve(l,r-1));
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &x[i]);
		p[i] = p[i-1] + x[i];
	}
	printf("%lld\n", solve(1, N));
}
