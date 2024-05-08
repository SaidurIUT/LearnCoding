// You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.
// A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements. 
// Input
// The first line contains an integer n: the size of the array.
// After this there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
// Output
// Print the length of the longest increasing subsequence.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// Example
// Input:
// 8
// 7 3 5 3 6 2 9 8

// Output:
// 4

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

int bit[MX];
int n;

void upd(int i, int val) {
	for (; i <= n; i += (i & (-i))) { bit[i] = (bit[i] + val) % MOD; }
}

int query(int i) {
	int res = 0;
	for (; i; i -= (i & (-i))) { res = (res + bit[i]) % MOD; }
	return res;
}

int main() {
	cin >> n;
	map<int, int> m;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		m[ar[i]]++;
	}
	int co = 0;
	for (auto &cur : m) { cur.second = ++co; }
	for (int &x : ar) { x = m[x]; }
	int sol = 0;
	for (int x : ar) {
		int subseq = 1 + query(x - 1);
		sol = (sol + subseq) % MOD;
		upd(x, subseq);
	}
	cout << sol << '\n';
}