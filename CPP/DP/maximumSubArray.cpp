#include<bits/stdc++.h>

using namespace std ; 

int main(){
    vector<int> array,dp ; 
    int n,temp;
    cin >> n ; 
    for(int i = 0 ; i<n ; i++){
        cin >> temp;
        array.push_back(temp);
    }

    dp.push_back(0);

    for(int i = 0 ; i < n ; i++){
        dp.push_back( max(array[i], dp[i]+array[i]));
    }

    int max_value = *max_element(dp.begin(), dp.end());

    cout << max_value << endl;
}

