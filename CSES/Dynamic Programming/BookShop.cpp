#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll n, ll x , vector<ll>&price , vector<ll>&pages){
    vector<ll>dp(x+1,0);

    for(int i = 0 ; i<n ; i++){
        for(int c = x ; c>0 ; c--){
            if(price[i] > c){
                continue;
            }

            dp[c] = max(dp[c], pages[i]+dp[c-price[i]]);
        }
    }

    return dp[x];

}



int main(){
    ll n,x;
    cin >> n >> x ;
    vector<ll>price(n);
    vector<ll>pages(n);

    for(ll i = 0 ; i< n ; i++){
        cin >> price[i];
    }


    for(ll i = 0 ; i< n ; i++){
        cin >> pages[i];
    }

    cout<<solve(n,x,price,pages)<<endl;
}