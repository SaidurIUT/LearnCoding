#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(int n , int x ,vector<int>&coins){
    ll mod = 10e9 +7; 
    vector<ll> dp(x+1,0);
    dp[0]=1;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0; j< n ; j++ ){
            if(coins[j]> i ){
                continue;
            }
            dp[i] = (dp[i] + dp[i - coins[j]])%mod;
        }
    }

    return dp[x];

}



int main(){
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i =0 ; i< n ; i++){
        cin >> coins[i];
    }

    cout << solve(n,x,coins)<<endl;

}