#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"enter row and collumn"<<endl;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int> (m,0));

    for(int i=0; i<n ;i++){
        for(int j=0 ; j< m ; j++){
            cout<<graph[i][j]<<" ";
        }

        cout << endl;
    }
}
