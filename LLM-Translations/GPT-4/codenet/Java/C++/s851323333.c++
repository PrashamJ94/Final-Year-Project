#include <iostream>
#include <list>
#include <iterator>

int main() {
    std::list<int> list;
    int input;

    while (std::cin >> input) {
        if (input == 0) {
            std::cout << list.front() << std::endl;
            list.pop_front();
        } else {
            list.push_front(input);
        }
    }

    return 0;
}
// 
