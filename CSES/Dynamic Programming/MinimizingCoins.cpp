#include<bits/stdc++.h>
#define ll long long int

using namespace std; 

ll solve (int n , int x , vector <int> coins){
    
    vector<ll> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int weight= 1 ; weight <= x ; weight++){
        for(int i = 1 ; i < n ; i++){
            if( weight - coins[i-1] >= 0 ){
                dp[weight] = min(dp[weight],dp[weight-coins[i]]+1);
            }
        }
    }

    return (dp[x]==INT_MAX ? -1 : dp[x]);
}

int main(){
    int n , x;
    cin >> n >> x; 
    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }
    cout<<solve(n,x,coins);



}

