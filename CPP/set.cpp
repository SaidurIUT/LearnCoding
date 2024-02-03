#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    s.insert(2);
    s.insert(5);
    s.insert(10);
    s.insert(69);

    for(auto i : s){
        cout<<i<<" ";
    }cout<<endl;

    //cout<<s[2]<<endl;      // this is illigal

    cout<<s.size();

    s.erase(10);

    s.erase(s.begin());

    set<int> :: iterator it;

    for(it = s.begin(); it != s.end() ; it++){
        cout<<*it<<" ";
    }cout<<endl;





}
