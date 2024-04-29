#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n ; 
    cin >> n ; 
    vector <long long > dp(n);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;

    for(int i=3; i <=n ; i++){
        dp[i] = dp[i-1] +dp[i-2];
    }

    cout<<dp[n];
    
}    