#include<bits/stdc++.h>
#define ll long long int

using namespace std; 

ll solve (int n , int x , vector <ll>& coins){
    
    vector<ll> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int weight= 1 ; weight <= x ; weight++){
        for(int i = 0 ; i < n ; i++){
            if (coins[i] > weight || dp[weight - coins[i]] == INT_MAX)
                continue;
            dp[weight] = min(dp[weight], dp[weight - coins[i]] + 1);
        }
    }

    return (dp[x]==INT_MAX ? -1 : dp[x]);
}

int main(){
    int n , x;
    cin >> n >> x; 
    vector<ll> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }
    cout<<solve(n,x,coins);

}

