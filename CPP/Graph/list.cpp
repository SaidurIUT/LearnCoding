#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    list<int> mylist[n];

    mylist[1].push_back(5);

    // Print the first element in the list at index 1
    cout << mylist[1].front() << endl;
    cout<<mylist[1].size()<<endl;
    cout<<mylist[2].size()<<endl;
    return 0;
}
