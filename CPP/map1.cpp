#include<iostream>
#include<map>
#include<string>

using namespace std;

// Map is an associative array

int main(){

    map<string , int> marksMap;
    
    marksMap["Saeed"] = 98;
    marksMap["Mokles"] = 59;
    marksMap["Kuddus"] = 34;
    marksMap.insert({{"Sokina",99},{"jorina",56}});

    map<string,int> :: iterator iter;
    for(iter = marksMap.begin() ; iter != marksMap.end() ; iter++ ){
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }




    return 0;


}