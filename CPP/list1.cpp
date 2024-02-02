#include<iostream>
#include<list>
#include<string>

using namespace std;
// list is a bidirectional 

void display(list<int>&lst){

    list<int> ::  iterator iter;

    for(iter= lst.begin(); iter != lst.end(); iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
}


int main(){
    list<int>list1; // list of 0 length
    list<int> list2(7); // empty list of size 7

    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(10);
    list1.push_back(51);
    list1.push_back(5);
    list1.push_back(5);

    display(list1);


    list1.sort();
    display(list1);

    list1.pop_back();

    display(list1);

    list1.push_front(69);

    display(list1);

    list1.pop_front();

    display(list1);

    list1.remove(5);
    display(list1);
    // list1.remove(5);
    // display(list1);

    list2.push_back(5);
    list2.push_back(7);
    list2.push_back(10);
    list2.push_back(51);
    list2.push_back(5);
    list2.push_back(5);
    list2.push_front(100);
    list2.push_front(10);

    display(list2);


    


}