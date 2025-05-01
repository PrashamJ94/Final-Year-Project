#include<iostream>
#include<list>
#include<string>

using namespace std;

void printList(list<int>& li) {
    for(auto it = li.begin(); it != li.end(); ++it) {
        if(it != li.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
}

int main() {
    int key, n;
    string com;
    list<int> li;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> com;
        if(com == "insert") {
            cin >> key;
            li.push_front(key);
        }
        else if(com == "deleteFirst") {
            li.pop_front();
        }
        else if(com == "deleteLast") {
            li.pop_back();
        }
        else {
            cin >> key;
            li.remove(key);
        }
    }
    printList(li);
    return 0;
}
// 
