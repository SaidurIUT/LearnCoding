#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll n , ll x ,vector<ll>&coins){
    ll mod = 1e9 +7; 
    vector<ll> dp(x+1,0);
    dp[0]=1;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = coins[i]; j<= x ; j++ ){
            dp[j] = (dp[j] + dp[j - coins[i]])%mod;
        }
    }

    return dp[x];

}
int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll> coins(n);
    for(ll i =0 ; i< n ; i++){
        cin >> coins[i];
    }

    cout << solve(n,x,coins)<<endl;

}