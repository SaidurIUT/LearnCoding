#include<bits/stdc++.h>
#define ll long long int 
using namespace std ;

ll solve (vector< vector<char> > &grid , ll n){
    ll mod =1e9+7;
    vector< vector<ll> > dp (n , vector<ll>(n,0));

    for(ll i =0 ; i<n ; i++){
        if(grid[i][0] == '*'){
            break;
        }
        dp[i][0] = 1;

    }


    for(ll i =0 ; i<n ; i++){
        if(grid[0][i] == '*'){
            break;
        }
        dp[0][i] = 1;

    }

    for(ll i = 1 ; i< n ; i++){
        for(ll j = 1 ; j < n ; j++){
            if(grid[i][j]=='*'){
                continue;
            }

            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }

    return dp[n-1][n-1];


}

int main(){
    ll n;
    cin >> n;

    vector<vector<char> > grid(n, vector<char>(n));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> grid[i][j]; 
        }
    }

    cout << solve(grid ,n);
}