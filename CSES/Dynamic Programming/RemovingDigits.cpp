#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n , step =0, temp,substractor;

    cin >> n ; 
    while(n){
        temp = n;
        substractor = temp%10;
        temp = temp/10;
        while(temp){
            substractor = max(substractor,temp%10);
            temp = temp/10;
        }

        n= n-substractor;
        step++;
    }

    cout<<step<<endl;
}