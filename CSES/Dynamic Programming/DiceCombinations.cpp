#include<bits/stdc++.h>
#define ll long long int
using namespace std; 

ll solve(ll n){
    ll mod = 1e9+7;
    vector<ll>dp(n+1);
    dp[0] = 1;

    for(ll i =1 ; i<= n ; i++){
        for(ll j = 1 ; j <=6 && j <= i  ; j++ ){
            dp[i] = (dp[i] + (dp[i-j])) % mod;
        }
    }

    return dp[n];
}

int main(){
    ll n;
    cin >> n;
    cout<< solve(n)<< endl ;
}