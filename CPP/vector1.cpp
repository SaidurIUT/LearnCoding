#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    vector<int> :: iterator it;

    for(it = v.begin(); it!=v.end();it++){
        cout<<*it<<" ";
    } cout<<endl;

    for(auto element:v){
        cout<<element<<" ";
    }cout<<endl;

    vector<int> v2(5,23);

    for(int i=0 ; i<v2.size() ; i++){
        cout << v2[i] << " ";
    }cout<<endl;
}